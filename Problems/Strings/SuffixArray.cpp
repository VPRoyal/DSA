#include <bits/stdc++.h>
using namespace std;
class SuffixArray
{
private:
    string str;
    vector<int> SA, RA, tempSA, tempRA, lcp, freq;
    int MAX_N = 100010, len;
    void countingSort(int k)
    {                                        // O(n)
        int i, sum, maxi = std::max(300, len); // Up to 255 ASCII chars or length of n
        // Reset the frequency array
        fill(freq.begin(), freq.end(), 0);
        // Count the frequency of each integer rank
        for (i = 0; i < len; i++)
        {
            int rank = (i + k < len) ? RA[i + k] : 0;
            freq[rank]++;
        }

        // Compute cumulative sums
        for (i = sum = 0; i < maxi; i++)
        {
            int t = freq[i];
            freq[i] = sum;
            sum += t;
        }

        // Shuffle the suffix array if necessary
        for (i = 0; i < len; i++)
        {
            int rank = (SA[i] + k < len) ? RA[SA[i] + k] : 0;
            tempSA[freq[rank]++] = SA[i];
        }

        // Update the suffix array
        for (i = 0; i < len; i++)
        {
            SA[i] = tempSA[i];
        }
    }

public:
    SuffixArray(string s)
    {
        if(s.empty()){
            cout<<"Empty String encountered! No function will run";
            return;
        }
        str = s;
        str += "$";
        len = str.length();
        SA.resize(len);
        RA.resize(len);
        tempSA.resize(len);
        tempRA.resize(len);
        lcp.resize(len);
        freq.resize(300, 0);
    }
    // Generate Suffix Array
    void createSA()
    {
        if (str.empty()) return;
        for (int i = 0; i < len; i++)
        {
            RA[i] = str[i];
            SA[i] = i;
        }
        for (int k = 1; k < len; k *= 2)
        {
             // Sort based on the second part
            countingSort(k); 
            // Stable sort based on the first part
            countingSort(0);  

            // reranking
            int r = 0;
            tempRA[SA[0]] = r;
            // Compare adjacent suffixes if same pair => same rank r; otherwise, increase r;
            for (int i = 1; i < len; i++)
            {
                tempRA[SA[i]]=(RA[SA[i]] == RA[SA[i - 1]] &&RA[SA[i] + k] == RA[SA[i - 1] + k])?r:++r;
            }
            // Update the rank array
            for (int i = 0; i < len; i++) RA[i] = tempRA[i];
            // All ranks are unique -- Optimization Technique
            if (RA[SA[len - 1]] == len - 1) break;
        }
    }
    
    // Make LCP (Longest Common prefix) Array in O(n) time.
    // Also known as Kasai algorithm
    void kasai(){
        if (str.empty()) return;
        int k=0;
        // Reseting length to string length by ignoring the end '$'.
        int length=len;
        vector<int>rank(len,0);
        for(int i=0;i<length;i++) rank[SA[i]] = i;
        for(int i=0;i<length;i++, k=max(k-1,0)){
            if(rank[i]==length-1) {k=0; continue;}
            int j = SA[rank[i]+1];
            while(i+k<length && j+k<length && str[i+k]==str[j+k]) k++;
            lcp[rank[i]] = k;
        }
    }
    void printLCPArray(){
        cout << "LCP array: ";
        for(int i = 0; i < len; i++){
            cout << lcp[i] << " ";
        }
        cout << endl;
    }
    void printSuffixArray(){
        // Ignoring the '$' character during printing.
        for(int i = 1; i < len; i++){
            cout << SA[i] << " ";
        }
        cout << endl;
    }
    vector<int> getSuffixArray(){ return SA; }
    vector<int> getLCPArray(){ return lcp; }
};

int main()
{
    string str = "banana";
    SuffixArray suffixArray(str);
    suffixArray.createSA();
    suffixArray.kasai();
    suffixArray.printLCPArray();
    return 0;
}