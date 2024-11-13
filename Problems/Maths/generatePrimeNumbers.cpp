#include <iostream>
#include <vector>
#include <cmath>

// Function to generate the first 'n' prime numbers
std::vector<int> generatePrimes(int n) {
    std::vector<int> primes; // To store the first 'n' primes
    if (n < 1) return primes; // Return empty if 'n' is less than 1

    // Estimation of upper bound for finding the nth prime
    int limit = n > 6 ? n * log(n) + n * log(log(n)) : 15;
    std::vector<bool> isPrime(limit + 1, true);

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p <= limit && primes.size() < n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
            // Mark multiples of p as non-prime
            for (int multiple = p * 2; multiple <= limit; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }
    
    // In case the limit was underestimated, expand it until we have 'n' primes
    int current = limit + 1;
    while (primes.size() < n) {
        bool isPrime = true;
        for (int p = 2; p * p <= current; ++p) {
            if (current % p == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(current);
        ++current;
    }

    return primes;
}

int main() {
    int i;
    std::cout << "Enter the number of primes to generate: ";
    std::cin >> i;

    std::vector<int> primes = generatePrimes(i);
    std::cout << "The first " << i << " prime numbers are:\n";
    for (int prime : primes) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;

    return 0;
}
