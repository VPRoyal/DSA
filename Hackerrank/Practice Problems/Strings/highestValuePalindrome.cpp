#include <iostream>
#include <string>
#include <vector>
using namespace std;

string highestValuePalindrome(string s, int n, int k) {
    vector<int> changes(n, 0); // Track changes made to the string

    // Step 1: Make the string a palindrome
    int left = 0, right = n - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            s[left] = s[right] = max(s[left], s[right]); // Make both sides equal
            changes[left] = 1; // Record that a change was made
            k--; // Reduce the available changes
            if (k < 0) {
                return "-1"; // Not enough changes to make it a palindrome
            }
        }
        left++;
        right--;
    }

    // Step 2: Maximize the palindrome
    left = 0;
    right = n - 1;
    while (left <= right && k > 0) {
        if (left == right) { // Handle the middle digit for odd-length strings
            if (k > 0 && s[left] != '9') {
                s[left] = '9';
                k--;
            }
        } else {
            if (s[left] != '9') {
                // If a change was already made, only 1 more change is needed
                if (changes[left] == 1 && k >= 1) {
                    s[left] = s[right] = '9';
                    k--;
                }
                // If no change was made yet, 2 changes are needed
                else if (changes[left] == 0 && k >= 2) {
                    s[left] = s[right] = '9';
                    k -= 2;
                }
            }
        }
        left++;
        right--;
    }

    return s;
}

int main() {
    // Example 1
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    cout << highestValuePalindrome(s, n, k) << endl;

    return 0;
}
