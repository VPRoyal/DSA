#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int d = 256;  // Number of characters in the input alphabet (for ASCII, use 256)
const int q = 101;  // A large prime number to minimize hash collisions

// Function to compute the hash value of a string
int hashValue(const string& str, int m) {
    int hash = 0;
    for (int i = 0; i < m; i++) {
        hash = (hash * d + str[i]) % q;  // Hash calculation: (d * hash + str[i]) % q
    }
    return hash;
}

// Function to search for the pattern in the text using Rabin-Karp algorithm
void rabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        cout << "Pattern is longer than the text." << endl;
        return;
    }

    // Precompute the hash value of the pattern
    int patternHash = hashValue(pattern, m);

    // Compute the hash value for the first window of the text
    int textHash = hashValue(text, m);

    // The value of d^(m-1) % q, used for rolling hash updates
    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Loop through the text to find the pattern
    for (int i = 0; i <= n - m; i++) {
        // If the hash values match, check for actual string match
        if (patternHash == textHash) {
            bool match = true;
            // Check for characters in the substring (if hashes matched)
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Compute the hash value for the next window in the text
        if (i < n - m) {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;

            // Ensure the hash is positive
            if (textHash < 0) {
                textHash += q;
            }
        }
    }
}

int main() {
    string text = "ababcababcababc";
    string pattern = "ababc";

    rabinKarp(text, pattern);

    return 0;
}
