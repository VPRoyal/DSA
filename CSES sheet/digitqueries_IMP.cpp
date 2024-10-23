#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#include <iostream>
#include <vector>

long long findDigitAtPosition(long long k) {
    long long digits = 1; // Number of digits in the current number range
    long long count = 9; // Count of numbers with `digits` digits
    long long start = 1; // Start of the current number range

    // Determine the range that contains the k-th digit
    while (k > digits * count) {
        k -= digits * count; // Decrease k by the number of digits in this range
        digits++; // Move to the next range
        count *= 10; // Move to the next power of 10
        start *= 10; // Move to the next range start
    }

    // Find the exact number and digit
    long long number = start + (k - 1) / digits; // Find the actual number
    std::string numberStr = std::to_string(number); // Convert the number to string
    return numberStr[(k - 1) % digits] - '0'; // Return the specific digit
}

int main() {
    int q;
    std::cin >> q; // Number of queries
    while (q--) {
        long long k;
        std::cin >> k; // Position to find the digit
        std::cout << findDigitAtPosition(k) << std::endl; // Output the digit
    }

    return 0;
}



/*
int main() {
    int t;
    cin>>t;
    long long a;
    while (t--)
    {
        cin>>a;
        bool loop=true;
        int i=1;
        long long digits=(log10(abs(a))) + 1;
        while(loop){
            long long nums=(pow(10,i)-pow(10,i-1))*i;
            if(a<=nums){
                loop=false;
                digits=i;
            }else{
                a-=nums;
            }
            i++;
        }
        long long base=pow(10,digits-1)-1;
        long long moves=a/digits;
        if(a%digits==0){
            cout<<(base+moves+1)%10<<endl;
        }else{
            int res=(base+moves+1)/pow(10,(digits-a%digits));
            cout<<res%10<<endl;
        }
    }
    
    return 0;
}

*/
