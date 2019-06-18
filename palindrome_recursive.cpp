// Recursive Function | Palindrome Word.
// A word is palindrome if its first and last characters are equal
// and the subword between those characters is a "palindrome".
// A contribution by Wael Assaf.
#include <iostream>
#include <string>
using namespace std;

bool Palindrome(string word) {
    if (word.length() <= 1)
        return true;
    if (word.at(0) != word[word.length() - 1])
        return false; 
    word = word.substr(1,  word.length() - 2);
    return Palindrome(word);        
}

int main () {
    string word;
    cout << "Please enter your word : ";
    cin >> word;
    if (Palindrome(word))
        cout << "This word is palindrome";
    else
        cout << "This word is not palindrome";
}
