#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate Z-array for a given string S
vector<int> calculateZArray(const string &S) {
    int n = S.length();
    vector<int> Z(n, 0);  // Initialize the Z-array with 0s
    int L = 0, R = 0;  // Initialize the interval [L, R] for the current window
    
    // Iterate through the string to compute the Z-array
    for (int i = 1; i < n; ++i) {
        if (i <= R) {
            // Case 1: i is within the interval [L, R], we use previously computed Z-values
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        
        // Attempt to extend the current window and compute Z[i]
        while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]]) {
            Z[i]++;
        }

        // Update the window [L, R]
        if (i + Z[i] - 1 > R) {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    
    return Z;
}

// Function to perform pattern matching using the Z-algorithm
vector<int> zAlgorithmPatternMatching(const string &P, const string &T) {
    // Concatenate pattern P and text T with a separator '$'
    string combined = P + "$" + T;
    int m = P.length();
    int n = T.length();
    
    // Calculate Z-array for the concatenated string
    vector<int> Z = calculateZArray(combined);
    
    // Store the results where Z[i] == m (length of pattern), meaning a match
    vector<int> result;
    
    for (int i = m + 1; i < Z.size(); ++i) {
        if (Z[i] == m) {
            result.push_back(i - m - 1);  // Match found at index (i - m - 1) in T
        }
    }
    
    return result;
}

int main() {
    // Input pattern and text
    string pattern, text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    cout << "Enter the text: ";
    cin >> text;
    
    // Perform pattern matching using Z-algorithm
    vector<int> matches = zAlgorithmPatternMatching(pattern, text);
    
    // Print the results
    if (matches.empty()) {
        cout << "No matches found." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int index : matches) {
            cout << index << " ";
        }
        cout << endl;
    }
    
    return 0;
}
