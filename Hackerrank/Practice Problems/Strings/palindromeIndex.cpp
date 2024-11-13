#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
bool isPalindrome(string str){
    string rev=str;
    reverse(rev.begin(), rev.end());
    return str==rev;
}
int palindromeIndex(string str){
    if(isPalindrome(str)) return -1;
    int s,e;
    for(s=0, e=str.size()-1;s<e;s++,e--){
        if(str[s]!=str[e]) break;
    }
    if(s>=e) return -1;
    string a=str, b=str;
    a.erase(a.begin()+s);
    if(isPalindrome(a)) return s;
    b.erase(b.begin()+e);
    if(isPalindrome(b)) return e;
    return -1;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        string str;
        cin>>str;
        int index=palindromeIndex(str);
        cout<<index<<endl;
    }
    return 0;
}
