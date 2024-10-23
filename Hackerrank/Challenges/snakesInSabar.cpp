#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long t;
    int n;
    cin>>t;
    while(t--){
    int z=0,o=0;
    cin>>n;
    while(n--){
        char c;
        cin>>c;
        if(c=='0') z++;
        else o++;
    }
    bool One=o%2==0, Zero=z%2==0;

    if(One&&!Zero) cout<<"Campus nahi banega"<<endl;
    else if(!One&&Zero) cout<<min(o,z)<<endl;
    else if(One&&Zero) cout<<z<<endl;
    else cout<<o<<endl;
    
    }
    return 0;
}
