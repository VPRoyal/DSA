#include <bits/stdc++.h>
using namespace std;
const int INF=100;
int get_two_combination(int substr_count)
{
    if(substr_count < 2)
    {
        return 0;
    }
    return substr_count * (substr_count-1) / 2;
}

int sherlockAndAnagrams(string s) 
{
    map<string, int> anagrams;
    int pair_count = 0;
    for(int i = 1; i < s.size(); i++)
    {
        for(int j = 0; (j + i) <= s.size(); j++)
        {
            string cur_substr = s.substr(j, i);
            sort(cur_substr.begin(), cur_substr.end());
            anagrams[cur_substr]++;
        }
    }
    for(auto it = anagrams.begin(); it != anagrams.end(); it++)
    {
        pair_count += get_two_combination(it->second);
    }
    return pair_count;
}
int main() {
string s;
cin>>s;

cout << sherlockAndAnagrams(s) << endl;
return 0;
}

