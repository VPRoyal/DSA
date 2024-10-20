#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string input;
    cin >> input; // Read the input string

    unordered_map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }

    int oddCount = 0;
    char oddChar;
    string halfPalindrome = "";

    // Check character frequencies
    for (const auto& pair : freq) {
        if (pair.second % 2 == 1) {
            oddCount++;
            oddChar = pair.first; // Store the character with an odd count
        }
        halfPalindrome += string(pair.second / 2, pair.first); // Append half the characters
    }

    // Check for palindrome possibility
    if ((input.length() % 2 == 0 && oddCount > 0) || (input.length() % 2 == 1 && oddCount > 1)) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    // Construct the full palindrome
    string palindrome = halfPalindrome;
    if (oddCount == 1) {
        palindrome += oddChar; // Add the odd character in the middle
    }
    palindrome += string(halfPalindrome.rbegin(), halfPalindrome.rend()); // Mirror the half

    cout << palindrome << endl; // Output the result
    return 0;
}



/*
Observations and Methods------>>>>>>

Count the Frequencies: Use a frequency array or a hash map to count occurrences of each character.
Check Palindrome Conditions:
Count how many characters have odd occurrences.
If the string length is odd, at most one character can have an odd count.
If the string length is even, there should be no characters with an odd count.
Construct the Palindrome:
If conditions are met, construct the palindrome by placing half of the characters on one side and mirroring them on the other side.
If a character has an odd frequency, place it in the middle.

*/
