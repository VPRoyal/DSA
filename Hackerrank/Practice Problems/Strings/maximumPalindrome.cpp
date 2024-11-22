#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int MOD = 1000000007;

// Precompute factorials and modular inverses for combinatorics
vector<long long> factorial(1e5 + 1, 1), inverseFactorial(1e5 + 1, 1);

// Modular exponentiation
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Precompute factorials and their modular inverses
void precomputeFactorials(int maxN) {
    for (int i = 2; i <= maxN; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    inverseFactorial[maxN] = modPow(factorial[maxN], MOD - 2, MOD);
    for (int i = maxN - 1; i >= 1; i--) {
        inverseFactorial[i] = (inverseFactorial[i + 1] * (i + 1)) % MOD;
    }
}

// Compute nCr modulo MOD
long long nCr(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return (factorial[n] * inverseFactorial[r] % MOD) * inverseFactorial[n - r] % MOD;
}

// Initialize prefix frequency array
vector<vector<int>> initialize(string s) {
    int n = s.size();
    vector<vector<int>> prefixFreq(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            prefixFreq[i + 1][j] = prefixFreq[i][j];
        }
        prefixFreq[i + 1][s[i] - 'a']++;
    }
    return prefixFreq;
}

// Answer queries
long long answerQuery(const vector<vector<int>>& prefixFreq, int l, int r) {
    vector<int> freq(26, 0);
    for (int i = 0; i < 26; i++) {
        freq[i] = prefixFreq[r][i] - prefixFreq[l - 1][i];
    }

    int oddCount = 0, pairs = 0;
    for (int count : freq) {
        pairs += count / 2;
        if (count % 2 != 0) oddCount++;
    }

    // Maximum palindrome length
    int maxLength = pairs * 2 + (oddCount > 0 ? 1 : 0);

    // Count of maximum-length palindromes
    long long result = 1;
    for (int count : freq) {
        if (count / 2 > 0) {
            result = (result * nCr(pairs, count / 2)) % MOD;
            pairs -= count / 2;
        }
    }
    if (oddCount > 0) result = (result * oddCount) % MOD;

    return result;
}

int main() {
    string s;
    int q;
    cin >> s >> q;

    precomputeFactorials(1e5); // Precompute factorials up to the size limit
    vector<vector<int>> prefixFreq = initialize(s);

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << answerQuery(prefixFreq, l, r) << endl;
    }

    return 0;
}


/*
-------->>>> Explanation
Key Observations:
Palindrome Construction:

A palindrome can be formed by reordering letters such that:
All letters appear an even number of times (for even-length palindromes).
At most one letter appears an odd number of times (for odd-length palindromes).
The maximum palindrome length is determined by summing all pairs of letters with even counts and possibly adding one center letter if any odd counts exist.
Query Handling:

Each query defines a substring. We need to:
Count the frequency of letters in that substring.
Compute the number of maximum-length palindromes that can be formed using the letters of the substring.
Efficient Preprocessing:

Using prefix frequency arrays, we can efficiently determine letter frequencies for any substring in 
𝑂
(
1
)
O(1).
Plan:
Preprocess the String:

Build a prefix frequency array for the 26 lowercase letters. This allows us to quickly compute the frequency of each letter in any substring.
Handle Queries:

For each query:
Calculate the frequency of each letter in the specified substring using the prefix frequency array.
Determine the maximum palindrome length that can be formed from these frequencies.
Count the number of distinct palindromes of this length using combinatorics.
Output Results:

For each query, output the count of maximum-length palindromes modulo 
1
0
9
+
7
10 
9
 +7.




Explanation:
Precomputations:

The initialize function builds the prefix frequency array for all 26 letters.
precomputeFactorials calculates factorials and their modular inverses for combinatorics.
Query Handling:

For each query, calculate the frequency of each letter in the substring using the prefix frequency array.
Compute the maximum palindrome length by summing pairs of letters and handling odd counts.
Use combinatorics (nCr) to calculate the number of distinct maximum-length palindromes.
Efficiency:

The prefix frequency array ensures 
𝑂
(
1
)
O(1) computation of letter frequencies for any substring.
Handling each query takes 
𝑂
(
26
)
=
𝑂
(
1
)
O(26)=O(1) time for counting, making the solution efficient.











*/












/*
<<<<<<<--------Another tested solution--------->>>>>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countPalindrome(string s) {
    vector<int> alphabet(26,0);
    for(char c : s){
        alphabet[c-'a']++;
    }
    int evenCount=0, oddCount=0, diffEven=0;
    for(int count : alphabet){
        if(count==0) continue;
        if(count%2==0){ 
            evenCount+=count/2;
            diffEven++;
        }
        if(count%2 != 0){
            evenCount+=(count-1)/2;
            oddCount++;
        }
    }
    if(evenCount){
        if(oddCount) return evenCount*oddCount;
        else if(diffEven==1) return 1;
        return evenCount;
    }
    else return oddCount;
}

int main() {
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<vector<int>> v;
    while (n--)
    {
       int l,r;
       cin>>l>>r;
       vector<int> res;
       res.push_back(l);
       res.push_back(r);
       string sub = s.substr(l-1, r-l+1);
    //    cout<<countPalindrome(sub)<<endl;
    res.push_back(countPalindrome(sub));
    v.push_back(res);
    }
    for(vector<int> vec:v){
        int res;
        cin>>res;
        cout<<vec[0]<<" "<<vec[1]<<" "<<res<<" "<<vec[2]<<endl;
    }
    

    return 0;
}



*/