#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        long long a, b;
        cin >> a >> b; // Read the number of coins in both piles

        // Check the conditions
        if ((a + b) % 3 == 0 && 2 * a >= b && 2 * b >= a) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}



// OBSERVATIONS --------->>>>>>>>

// From the two operations, we can derive some useful observations:

// Total Coins: Each operation reduces the total number of coins by 3. Therefore, the sum 
// 𝑎
// +
// 𝑏
// a+b must be divisible by 3 for it to be possible to empty both piles.

// Maximum Coins Removal: For each operation, we need to ensure that neither pile becomes negative. Specifically:

// In the first operation, we cannot remove more coins than are available in each pile.
// This leads us to the constraint that at no point can the number of coins in one pile exceed twice the number in the other pile. 
//This is derived from the fact that if one pile has too many coins compared to the other, it won't be possible to perform the operations without running out of coins in one pile.