#include "kmp.hpp"
// Function to create lps array
namespace KMP{
std::vector<int> computePrefix(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> prefix(m, 0);
    int j = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            prefix[i] = ++j;
        }
    }
    return prefix;
}

// Function to count occurences of pattern in string
int countOccurrences(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    std::vector<int> prefix = computePrefix(pattern);
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            ++count;
            j = prefix[j - 1];
        }
    }
    return count;
}
}
