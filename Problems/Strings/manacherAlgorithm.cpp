#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Preprocess the string by adding '#' between characters and around the string
string preprocessString(const string& s) {
    string result = "#";
    for (char ch : s) {
        result += ch;
        result += "#";
    }
    return result;
}

string manacher(const string& s) {
    // Step 1: Preprocess the string
    string T = preprocessString(s);
    int n = T.size();  // Size of the transformed string
    
    // Step 2: Array to store the lengths of the palindromes
    vector<int> P(n, 0);  // P[i] will be the radius of the palindrome centered at i
    
    int C = 0, R = 0;  // C is the center of the current rightmost palindrome, R is its right boundary
    int maxLength = 0, centerIndex = 0;  // To track the longest palindrome found
    
    // Step 3: Manacher's Algorithm main loop
    for (int i = 0; i < n; ++i) {
        // Mirror of i with respect to center C
        int mirror = 2 * C - i;
        
        // If i is within the right boundary, use the mirror to initialize P[i]
        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }
        
        // Expand the palindrome centered at i
        while (i - P[i] >= 0 && i + P[i] < n && T[i - P[i]] == T[i + P[i]]) {
            P[i]++;
        }
        
        // If we've expanded beyond the right boundary, update center and right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        
        // Track the longest palindrome found
        if (P[i] > maxLength) {
            maxLength = P[i];
            centerIndex = i;
        }
    }
    
    // Step 4: Extract the longest palindrome from the original string
    // Calculate the starting index of the palindrome in the transformed string
    int start = (centerIndex - maxLength) / 2;  // We divide by 2 to get the actual start in the original string
    return s.substr(start, maxLength-1);  // Return the longest palindromic substring
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    
    string longestPalindrome = manacher(input);
    cout << "The longest palindromic substring is: " << longestPalindrome << endl;
    
    return 0;
}
