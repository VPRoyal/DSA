#include <iostream>
#include <vector>
#include <string>

void generateGrayCode(int n) {
    int totalCodes = 1 << n; // Calculate 2^n
    for (int i = 0; i < totalCodes; ++i) {
        // Calculate Gray code
        int grayCode = i ^ (i >> 1);
        
        // Convert to binary string
        std::string binary;
        for (int j = n - 1; j >= 0; --j) {
            binary += (grayCode & (1 << j)) ? '1' : '0';
        }
        
        // Print the Gray code
        std::cout << binary << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n; // Read the input for n
    generateGrayCode(n); // Generate and print the Gray code sequence
    return 0;
}
