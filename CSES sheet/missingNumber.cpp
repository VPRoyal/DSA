#include <iostream>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long sumOfNumbers=(n * (n + 1)) / 2;
    long long actualSum = 0;
    while(n>1){
        long long a;
        cin>>a;
        actualSum+=a;
        n--;
    }
    cout<<sumOfNumbers-actualSum;
}



// ------->> O(n) way to write the output file
// int main(){
//     long long n;
//     cin>>n;
//     int num[n]={};
//     long long m=n;
//     while (m>1)
//     {
//         long long a;
//         cin>>a;
//         num[a-1]=1;
//         m--;
//     }
//     m=0;
//      while (m<n)
//     {
//         if(num[m]==0) {
//             cout<<m+1;
//             return 0;
//         }
//         m++;
//     }
    
//     return 0;
// }