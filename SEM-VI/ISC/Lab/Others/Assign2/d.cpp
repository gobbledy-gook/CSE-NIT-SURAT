#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


string decryptCaesarCipher(const string& ciphertext) {
    const string alphabet = "abcdefghijklmnopqrstuvwxyz";
    
    // Initialize a vector to store the frequency of each letter
    vector<int> frequency(26, 0);
    
    // Count the frequency of each letter in the ciphertext
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            int index = tolower(ch) - 'a';
            frequency[index]++;
        }
    }
    
    // Find the most frequent letter in the ciphertext
    auto max_iter = max_element(frequency.begin(), frequency.end());
    int max_index = distance(frequency.begin(), max_iter);
    int shift = (max_index + 26 - ('e' - 'a')) % 26; // Calculate the shift
    
    // Decrypt the ciphertext using the calculated shift
    string plaintext;
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char decrypted_char = (isupper(ch) ? 'A' : 'a') + (ch - (isupper(ch) ? 'A' : 'a') - shift + 26) % 26;
            plaintext.push_back(decrypted_char);
        } else {
            plaintext.push_back(ch); // Preserve non-alphabetic characters
        }
    }
    
    return plaintext;
}

int main() {
    string ciphertext;
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);
    
    string plaintext = decryptCaesarCipher(ciphertext);
    
    cout << "Decrypted text: " << plaintext << endl;
    
    return 0;
}
