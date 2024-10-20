#include <iostream>
int main(){
    long long n;
    std::cin >> n;
    int sum=0;
    long long p=5;
    while(p<=n){
        sum+=n/p;
        p*=5;
    }
    std::cout << sum;
    return 0;
}