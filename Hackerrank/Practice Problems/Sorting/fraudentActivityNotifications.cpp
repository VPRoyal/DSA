#include <bits/stdc++.h>
using namespace std;
#define ll long long unsigned int
long double findMedian(ll d, vector<ll>&freqArray){
    bool isEven=(d%2==0);
    ll pointer=(d+1)/2;
    int i=0;
    ll total=0;
    while(true){
        total+=freqArray[i];
        if(pointer<=total){
            if(isEven){
                if(pointer==total) return (2*i+1)/2.0;
                return i;
            }
            return i;
        }else i++;
    }
}
int main(){
    ll n,d, count=0;
    cin>>n>>d;
    vector<int> expd(n);
    vector<ll> freqArray(201,0);
    for(ll i=0;i<n;i++){
        expd[i]=0;
        cin>>expd[i];
        if(i<d){
            freqArray[expd[i]]++;
        }
    }
    for(ll j=d;j<n;j++){
        long double median=findMedian(d, freqArray);
        if(expd[j]>= (2*median)) count++;
        freqArray[expd[j-d]]--;
        freqArray[expd[j]]++;
    }
    cout<<count;
    return 0;
}