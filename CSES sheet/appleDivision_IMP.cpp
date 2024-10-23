#include <iostream>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

int main() {
    int n;
    std::cin >> n; // Read number of apples
    std::vector<int> weights(n);
    long long totalWeight = 0;

    // Read weights and calculate total weight
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
        totalWeight += weights[i];
    }

    long long minDiff = std::numeric_limits<long long>::max();

    // Generate all subsets
    for (int i = 0; i < (1 << n); ++i) {
        long long subsetWeight = 0;

        // Calculate weight of the current subset
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subsetWeight += weights[j];
            }
        }

        // Calculate the difference between the two groups
        long long otherWeight = totalWeight - subsetWeight;
        long long diff = std::abs(subsetWeight - otherWeight);

        // Update minimum difference
        minDiff = std::min(minDiff, diff);
    }

    // Output the minimum difference
    std::cout << minDiff << std::endl;

    return 0;
}





// int main() {
//     int n;
//     std::cin >> n;
//     long long a[n]={};
//     long long sum=0;
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//         sum+=a[i];
//     };
    
//     sort(a, a + n);
//     long long def=INT_MAX;
//     long long b=a[n-1];
//     def=min(def,abs(sum-2*b));
//     for (int i = 0; i < n-1; i++)
//     {
//         b+=a[i];
//         def=min(def,abs(sum-2*b));
//     }
//     cout<<def<<endl;
//     return 0;
// }
