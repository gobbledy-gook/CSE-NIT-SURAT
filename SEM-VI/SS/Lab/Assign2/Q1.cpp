#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isWhitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' || c == '<' || c == '>');
}

bool isDelimiter(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == ',' || c == ';');
}

bool isAlphanumeric(char c) {
    return (isalnum(c) || c == '_');
}

void processToken(const string& token) {
    cout << "Token: " << token << endl;
}

void tokenize(const string& code) {
    string token;
    bool inToken = false;

    for (char c : code) {
        if (isWhitespace(c) || isOperator(c) || isDelimiter(c)) {
            if (inToken) {
                processToken(token);
                token.clear();
                inToken = false;
            }
            if (!isWhitespace(c)) {
                processToken(string(1, c));
            }
        } else if (isAlphanumeric(c)) {
            token += c;
            inToken = true;
        }
    }

    if (inToken) {
        processToken(token);
    }
}

int main() {
    ifstream inputFile("test.cpp");  // Replace "input.cpp" with the actual filename

    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string code((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    tokenize(code);

    return 0;
}
