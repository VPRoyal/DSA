#include <bits/stdc++.h>

using namespace std;

int calcMinSwap(vector<pair<long long ,int>> arr) {
    int ascSwap=0, desSwap=0;
    sort(arr.begin(), arr.end());
    vector<pair<long long, int>> rev(arr);
    for(int i=0;i<arr.size();++i){
        if(i==arr[i].second) continue;
        else{
            ascSwap++;
            pair<long long ,int> temp;
            temp=arr[arr[i].second];
            arr[arr[i].second]=arr[i];
            arr[i]=temp;
            --i;
        }
    }
    reverse(rev.begin(), rev.end());
    for(int i=0;i<arr.size();++i){
        if(i==rev[i].second) continue;
        else{
            desSwap++;
            pair<long long ,int> temp;
            temp=rev[rev[i].second];
            rev[rev[i].second]=rev[i];
            rev[i]=temp;
            --i;
        }
    }
    return min(desSwap, ascSwap);
}

int main()
{
    int n;
    cin>>n;
    vector<pair<long long ,int>> arr;
    for(int i=0; i<n; i++){
        long long a;
        pair<long long, int> pr;
        cin>>a;
        pr.first=a;
        pr.second=i;
        arr.push_back(pr);
    }
    int res=calcMinSwap(arr);
    cout<<res<<'\n';

    return 0;
}
