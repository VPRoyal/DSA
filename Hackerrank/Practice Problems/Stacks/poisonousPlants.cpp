#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
int main(){
    int n;
    cin>>n;
    vector<ll> plants(n,0);
    vector<int> days(n,0);
    stack<int> track;
    int maxDays=0;
    for(int i=0;i<n;i++){
        cin>>plants[i];
        int day=0;
        while(!track.empty() && plants[track.top()]>=plants[i]){
            day=max(day, days[track.top()]);
            track.pop();
        }
        if(!track.empty()) day++;
        else day=0;
        days[i]=day;
        maxDays=max(maxDays, day);
        track.push(i);
    }
    cout<<maxDays<<endl;
    return 0;
}
