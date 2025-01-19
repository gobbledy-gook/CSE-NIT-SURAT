#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

// Structure to represent productions in the grammar
struct Production {
    char non_terminal;
    string production;
};

// Structure to represent LR(1) items
struct LRItem {
    char non_terminal;
    string production;
    int dot_index;
    set<char> lookahead;

    bool operator==(const LRItem& other) const {
        return non_terminal == other.non_terminal &&
               production == other.production &&
               dot_index == other.dot_index &&
               lookahead == other.lookahead;
    }
};

// Structure to represent LR(1) items sets
struct LRItemSet {
    vector<LRItem> items;

    bool operator==(const LRItemSet& other) const {
        return items == other.items;
    }
};

// Comparison function for LRItem
struct LRItemComparator {
    bool operator()(const LRItem& lhs, const LRItem& rhs) const {
        // Define a comparison logic for LRItem
        if (lhs.non_terminal != rhs.non_terminal)
            return lhs.non_terminal < rhs.non_terminal;
        if (lhs.production != rhs.production)
            return lhs.production < rhs.production;
        if (lhs.dot_index != rhs.dot_index)
            return lhs.dot_index < rhs.dot_index;
        return lhs.lookahead < rhs.lookahead;
    }
};

// Function to read the grammar from a text file
vector<Production> readGrammar(const string& filename) {
    vector<Production> grammar;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            char non_terminal = line[0];
            string production = line.substr(3);
            grammar.push_back({non_terminal, production});
            cout << non_terminal << "  " << production << endl;
        }
        file.close();
    }
    return grammar;
}

LRItemSet computeClosure(const LRItemSet& itemSet, const vector<Production>& grammar) {
    cout << "computeClosure begins" << endl;
    LRItemSet closure = itemSet;
    set<LRItem, LRItemComparator> closureSet(closure.items.begin(), closure.items.end()); // Convert items to set with custom comparison function
    bool added;
    do {
        added = false;
        for (const LRItem& item : closure.items) {
            cout << item.dot_index << "  " << item.non_terminal << " -- " << item.production[item.dot_index]  << endl;
            if (item.dot_index < item.production.size() && isupper(item.production[item.dot_index])) {
                char next_symbol = item.production[item.dot_index];
                for (const Production& prod : grammar) {
                    if (prod.non_terminal == next_symbol) {
                        LRItem newItem = {prod.non_terminal, prod.production, 0, {}};
                        if (closureSet.find(newItem) == closureSet.end()) { // Check if item already exists
                            newItem.lookahead.insert(item.lookahead.begin(), item.lookahead.end());
                            closure.items.push_back(newItem);
                            closureSet.insert(newItem); // Insert into closure set
                            added = true;
                        }
                    }
                }
            }
            // Additional condition to handle the case where the dot is at the end of a production
            else if (item.dot_index == item.production.size()) {
                added=false;
                continue;
                // Skip processing as dot is already at the end of the production
            }
            else if(!isupper(item.production[item.dot_index])){
                LRItem newItem = {item.non_terminal, item.production, 0, {}};
                if (closureSet.find(newItem) == closureSet.end()) { // Check if item already exists
                            newItem.lookahead.insert(item.lookahead.begin(), item.lookahead.end());
                            closure.items.push_back(newItem);
                            closureSet.insert(newItem); // Insert into closure set
                            added = true;
            }
            } 
        }
    } while (added);
    return closure;
}


// Function to compute goto operation on an LR(1) item set
LRItemSet goTo(const LRItemSet& itemSet, char symbol, const vector<Production>& grammar) {
    cout << "goTo begins" << endl;
    LRItemSet goToSet;
    for (const LRItem& item : itemSet.items) {
        if (item.dot_index < item.production.size() && item.production[item.dot_index] == symbol) {
            LRItem newItem = item;
            newItem.dot_index++;
            goToSet.items.push_back(newItem);
        }
    }
    return computeClosure(goToSet, grammar);
}

// Function to construct the LR(1) parse table
map<pair<int, char>, pair<char, int>> constructParseTable(const vector<Production>& grammar) {
    cout << "constructing parse table begins" << endl;
    map<pair<int, char>, pair<char, int>> parseTable;
    vector<char> symbols;
    for (const Production& prod : grammar) {
        for (char symbol : prod.production) {
            if (isupper(symbol) && find(symbols.begin(), symbols.end(), symbol) == symbols.end()) {
                symbols.push_back(symbol);
            }
        }
    }
    symbols.push_back('$'); // Add end of input marker
    vector<LRItemSet> canonicalCollection;
    LRItem startItem = {grammar[0].non_terminal, grammar[0].production, 0, {'$'}};
    LRItemSet startItems;
    startItems.items = {startItem};
    LRItemSet startSet = computeClosure(startItems, grammar);
    canonicalCollection.push_back(startSet);
    for (size_t i = 0; i < canonicalCollection.size(); ++i) {
        const LRItemSet& itemSet = canonicalCollection[i];
        for (char symbol : symbols) {
            LRItemSet goToSet = goTo(itemSet, symbol, grammar);
            if (!goToSet.items.empty()) {
                auto it = find(canonicalCollection.begin(), canonicalCollection.end(), goToSet);
                int nextState = it - canonicalCollection.begin();
                parseTable[{i, symbol}] = {'S', nextState}; // Shift operation
            }
        }
        for (const LRItem& item : itemSet.items) {
            if (item.dot_index == item.production.size()) {
                if (item.non_terminal == grammar[0].non_terminal) {
                    parseTable[{i, '$'}] = {'A', 0}; // Accept operation
                } else {
                    for (char lookahead : item.lookahead) {
                        auto it = find_if(grammar.begin(), grammar.end(), [&](const Production& p) {
                            return p.non_terminal == item.non_terminal && p.production == item.production;
                        });

                        if (it != grammar.end()) {
                            int productionIndex = distance(grammar.begin(), it);
                            parseTable[{i, lookahead}] = {'R', productionIndex};
                        }

                    }
                }
            }
        }
    }
    return parseTable;
}

// Function to parse input using constructed parse table
bool parseInput(const string& input, const map<pair<int, char>, pair<char, int>>& parseTable, vector <Production> &grammar) {
    cout << "parsing input begins" << endl;
    stack<int> stateStack;
    stateStack.push(0);
    size_t inputIndex = 0;
    while (inputIndex < input.size()) {
        int currentState = stateStack.top();
        char currentSymbol = input[inputIndex];
        auto it = parseTable.find({currentState, currentSymbol});
        if (it != parseTable.end()) {
            char action = it->second.first;
            int nextState = it->second.second;
            if (action == 'S') {
                stateStack.push(nextState);
                inputIndex++;
            } else if (action == 'R') {
                // Reduce
                Production prod = grammar[nextState];
                int numPop = prod.production.size();
                for (int i = 0; i < numPop; ++i) {
                    stateStack.pop();
                }
                currentState = stateStack.top();
                stateStack.push(parseTable.at({currentState, prod.non_terminal}).second);
            } else if (action == 'A') {
                return true; // Accept
            }
        } else {
            // No valid action found
            return false;
        }
    }
    return false;
}

int main() {
    vector<Production> grammar = readGrammar("/Users/garvitshah/Desktop/College/VI/SS/Lab/Assign6/gram.txt");

    // Construct LR(1) parse table
    map<pair<int, char>, pair<char, int>> parseTable = constructParseTable(grammar);

    // Input string
    string input;
    cout << "Enter the input string: ";
    cin >> input;

    // Parse input using constructed parse table
    if (parseInput(input + "$", parseTable, grammar)) {
        cout << "Input can be accepted!\n";
    } else {
        cout << "Input cannot be accepted.\n";
    }

    return 0;
}
