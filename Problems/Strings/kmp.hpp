#ifndef KMP_HPP
#define KMP_HPP

#include <vector>
#include <string>

class KMP {
public:
    // Function to count occurrences of pattern in text
    static int countOccurrences(const std::string& text, const std::string& pattern);

private:
    // Function to create lps array
    static std::vector<int> computePrefix(const std::string& pattern);
};

#endif // KMP_HPP
