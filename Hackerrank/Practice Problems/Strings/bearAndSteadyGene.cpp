#include <bits/stdc++.h>
using namespace std;

// Will find the minimum length required to make the string steady using Sliding Window Techniques.
// Solution of this problem can be found by sliding the left and right indices of the window such that it contain the
// minimum length required so that the string will remain steady or below the length as per the given conditions.
int steadyGene(int n,string str){
    unordered_map<char,int> gene;
    int target=n/4;
    int minLength=0;
    // Defining left-right index
    int i=0, j=n-1;
    while(j>=i){
        if(gene[str[j]]==target){
            j++;
            break;
        }
        gene[str[j]]++;
        j--;
    }
    if(j<0) return 0;
    while(j<n){
        gene[str[i]]++;
        while(j<n&&gene[str[j]]==target){
            gene[str[j]]--;
            j++;
        }
        int len=j-i-1;
        minLength=min(minLength,len);
    }
    return minLength;
}
int main() {
    int n;
    cin>>n;
    string str;
    cin>>str;
    int minLength=steadyGene(n,str);
}



/*
Second Code Methodology--------->>>>>
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int steadyGene(string gene) {
    int n = gene.length();
    int target = n / 4; // Each character should appear at most `n/4` times.
    unordered_map<char, int> freq; // To store frequencies of each character.
    
    // Step 1: Count the frequency of each character in the gene.
    for (char c : gene) {
        freq[c]++;
    }

    // Step 2: Determine if the gene is already steady.
    if (freq['A'] <= target && freq['C'] <= target && freq['G'] <= target && freq['T'] <= target) {
        return 0; // No substring needs to be replaced.
    }

    // Step 3: Sliding window approach to find the smallest substring.
    int left = 0, min_length = n;
    for (int right = 0; right < n; ++right) {
        // Reduce the frequency of the current character (as if it's being removed).
        freq[gene[right]]--;

        // Check if the gene is steady after removing the substring gene[left:right+1].
        while (freq['A'] <= target && freq['C'] <= target && freq['G'] <= target && freq['T'] <= target) {
            min_length = min(min_length, right - left + 1);
            // Shrink the window from the left.
            freq[gene[left]]++;
            left++;
        }
    }

    return min_length;
}

int main() {
    int n;
    string gene;
    cin >> n >> gene;
    cout << steadyGene(gene) << endl;
    return 0;
}

*/
