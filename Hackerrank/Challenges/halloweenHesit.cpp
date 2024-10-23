#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll unsigned long long int

int main() {
    int T;
    cin >> T;
    while (T--)
    {
       ll N,M;
       cin >> N >> M;
       while (N--)
       {
        ll a;
        cin>>a;
        if(a%2==0) cout<<"NO";
        else if(!(((a+1) & a) == 0)) cout<<"NO";
        else{
            ll po=log2(a+1)-1;
            ll res=floor((M-pow(2,po))/(a+1));
            cout<<"YES "<<res+1;
        }
        cout<<'\n';
       }
       
    }
     
    return 0;
}
