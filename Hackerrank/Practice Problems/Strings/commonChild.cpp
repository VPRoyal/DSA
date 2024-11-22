#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequence(string& s1, string& s2, int i,int j, vector<vector<int>>& dp) {
        if(i==s1.length() || j==s2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(s1[i]==s2[j]){
            ans= 1+longestCommonSubsequence(s1, s2, i+1,j+1, dp);
        }else{
            ans=max(longestCommonSubsequence(s1, s2, i+1,j, dp), longestCommonSubsequence(s1,s2,i,j+1, dp));
        }
        return dp[i][j]= ans;
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size(), vector<int>(s1.size(),-1));
    int length=longestCommonSubsequence(s1,s2,0,0, dp);
    cout<<length<<endl;
    return 0;
}
