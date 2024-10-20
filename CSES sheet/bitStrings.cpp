#include <iostream>
#include <math.h>
using namespace std;

const int MOD = 1000000007;
int main(){
    long long n;
    cin >> n;
    if(n<30){
        cout << static_cast<long long>(pow(2, n)) % MOD << endl;
    }else{
        long long m=n/30;
        long long r=n%30;
        long long sum=1;
        for(int i=1; i<=m; i++){
            sum*=static_cast<long long>(pow(2,30));
            sum%=MOD;
        }
        sum*=pow(2,r);
        sum%=MOD;
        cout << sum << endl;
    }
    return 0;
}