#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, sum;
    vector<long long> a, b;
    cin >> n;
    sum=n*(n+1)/2;
    if(sum%2!=0){
        cout << "NO" << endl;
        return 0;
    }
    sum/=2;
    cout << "YES" <<endl;
    while (n>0)
    {
       if(n<=sum){
        a.push_back(n);
        sum-=n;
       }else b.push_back(n);
       n--;
    }
    cout << a.size() << endl;
    for(auto x: a) cout << x << " ";
    cout << endl;
    cout << b.size() << endl;
    for(auto x: b) cout << x << " ";
    cout << endl;
    
    return 0;
}