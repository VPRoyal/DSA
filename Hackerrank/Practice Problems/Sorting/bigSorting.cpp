#include <bits/stdc++.h>

#define ll long long unsigned int
using namespace std;
bool compare(string &a, string &b){
    // First compare by length
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    // If lengths are equal, compare lexicographically
    return a < b;
}
int main(){
    ll n;
    cin>>n;
    vector<string> arr;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), compare);
    for (string a : arr) {
        cout<<a;
        cout<<'\n';
    }
    return 0;
}