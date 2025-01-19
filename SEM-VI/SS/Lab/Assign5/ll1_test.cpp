#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map <string, vector<vector<string>>>grammar;
unordered_map <string, vector<string>>firstof;

bool isTerminal(string T, vector <string> terminals){
    for(int i = 0; i < terminals.size(); i++){
        if(T == terminals[i]){
            return true;
        }
    }
    return false;
}

bool isVisited(string T, vector <string> &visited){
    for(int i = 0; i < visited.size(); i++){
        if(T == visited[i]){
            return true;
        }
    }
    return false;
}

void append(vector <string> &firstT, string rule){
    return;
}

vector<string> first(string T, vector <string> terminals, vector <string> nonterminals, vector <string> &visited){
    vector <string> firstT;
    for(int i = 0; i < grammar[T].size(); i++){
        if(isTerminal(grammar[T][i][0], terminals)){
            firstT.push_back(grammar[T][i][0]);
        }
        else{
            if(isVisited(grammar[T][i][0], visited)){
                append(firstT, grammar[T][i]);
                // for(int j = 0; j < firstof[grammar[T][i][0]].size(); j++){
                //     firstT.push_back(firstof[grammar[T][i][0]][j]);
                // }
            }
        }
    }
    visited.push_back(T);
    return firstT;
}

int main(){
    grammar["E"] = {{"T", "E'"}};
    grammar["E'"] = {{"+", "T", "E'"}, {"NULL"}};
    grammar["T"] = {{"F", "T'"}};
    grammar["T'"] = {{"*", "F", "T'"},{"NULL"}};
    grammar["F"] = {{"id"}, {"(", "E", ")"}};


    vector <string> terminals = {"+", "*", "id", "(", ")", "NULL"};
    vector <string> nonTerminals = {"E", "E'", "T", "T'", "F"};
    vector <string> visited = {};

    for(int i = nonTerminals.size()-1; i >= 0; i--){
        cout << "\n"<<i;
        cout << " " << nonTerminals[i] << "\t" << " :: ";
        firstof[nonTerminals[i]] = first(nonTerminals[i], terminals, nonTerminals, visited);
        for(int j = 0; j < firstof[nonTerminals[i]].size(); j++){
            cout << firstof[nonTerminals[i]][j] << ", ";
        }
        // cout << " ooo ";
    }

    return 0;
}