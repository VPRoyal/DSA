#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void generatePermutations(std::string &s, int start, std::set<std::string> &result) {
    if (start == s.length() - 1) {
        result.insert(s); // Insert the current permutation into the set
        return;
    }

    for (int i = start; i < s.length(); ++i) {
        std::swap(s[start], s[i]); // Swap to create a new permutation
        generatePermutations(s, start + 1, result); // Recur for the next index
        std::swap(s[start], s[i]); // Backtrack to restore the original string
    }
}

int main() {
    std::string input;
    std::cin >> input; // Read the input string

    std::set<std::string> result; // Set to store unique permutations
    generatePermutations(input, 0, result); // Generate permutations

    // Convert the set to a sorted vector
    std::vector<std::string> sortedResult(result.begin(), result.end());
    std::sort(sortedResult.begin(), sortedResult.end()); // Sort the results

    std::cout << sortedResult.size() << std::endl; // Print the count of unique strings
    for (const auto &str : sortedResult) {
        std::cout << str << std::endl; // Print each unique permutation
    }

    return 0;
}
