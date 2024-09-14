#include <string.h>
#include <bitset>
#include "hammingDistance.hpp"

namespace HammingDistance{
int calculateDistance(std::string a, std::string b) {
    int c = std::stoi(a, nullptr, 2);
    int d = std::stoi(b, nullptr, 2);
    return __builtin_popcount(c^d);
}
}