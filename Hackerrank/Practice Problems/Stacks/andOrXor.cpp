#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long 

int main(){
    ll n;
    cin>>n;
    vector<ll> elem(n,0);
    for(ll i=0;i<n;i++){
        cin>>elem[i];
    }
    stack<ll> track;
    ll maxXOR=0;
    for(ll i=0;i<n;i++){
        while(!track.empty()&&elem[track.top()]>=elem[i]){
            maxXOR=max(maxXOR, elem[track.top()]^elem[i]);
            track.pop();
        }
        if(!track.empty()) maxXOR=max(maxXOR, elem[track.top()]^elem[i]);
        track.push(i);
    }
    cout<<maxXOR;
    return 0;
}


/// One test case is not passed
// int main(){
//     ll n;
//     cin>>n;
//     vector<ll> elem(n,0);
//     for(ll i=0;i<n;i++){
//         cin>>elem[i];
//     }
//     ll f=-1, s=-1;
//     ll maxXOR=0;
//     for(ll i=0;i<n-1;i++){
//         if(f>0&&elem[i+1]<elem[f]&&elem[i+1]>elem[s]&&f>s){
//                 maxXOR=max(maxXOR, elem[i+1]^elem[s]);
//             }
//         if(elem[i]>=elem[i+1]){
//             f=i;
//             s=i+1;
//         }else if(elem[i]<elem[i+1]){
//             f=i+1;
//             s=i;
//         }
//         maxXOR=max(maxXOR, elem[f]^elem[s]);
//     }
//     cout<<maxXOR;
//     return 0;
// }