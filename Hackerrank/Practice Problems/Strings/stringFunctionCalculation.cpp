//------->>>>> Method-2 - Using Suffix Arrays <<<<<---------------

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
    int getMaxAreaRectangleOfHistogram(){
        stack<int> s;  // Stack to store indices of the histogram bars
    int maxArea = 0;  // Variable to store the maximum area
    int n = lcp.size();

    // Iterate through all bars of the histogram
    for (int i = 0; i <= n; ++i) {
        // While the current bar is shorter than the bar at the stack's top
        while (!s.empty() && (i==n||lcp[s.top()] > lcp[i])) {
            int h = lcp[s.top()];  // Height of the bar at the top of the stack
            s.pop();  // Pop the top element

            // Determine the width of the rectangle formed by the popped bar
            int width = s.empty() ? i : i - s.top() - 1;

            // Calculate area and update maxArea
            maxArea = max(maxArea, h * width);
        }

        // Push the current index onto the stack
        s.push(i);
    }
     return maxArea;
    }
};

int main(){
    string s;
    cin>>s;
    SuffixArray suffixArray(s);
    suffixArray.createSA();
    suffixArray.kasai();
    // Consider each LCP length as the length of the bar and find the largest rectangle in the histogram
    // That will be equivalent to our current requirements.
    int maxArea=suffixArray.getMaxAreaRectangleOfHistogram();
    if(maxArea>s.size()) cout<<maxArea<<endl;
    else cout<<s.size()<<endl;
}









/*
------->>>>> Method-2 - Using Suffix sort <<<<<---------------

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define nb nexta
#define head height
#define rank b

const int maxn = 100010;
char s[maxn];
int n, id[maxn], height[maxn], b[maxn], nexta[maxn];

bool cmp(const int& i, const int& j)
{
    return s[i] < s[j];
}

void SuffixSort()
{
    int i, j, k, h;
    for (i = 0; i < n; i++) id[i] = i;
    sort(id, id + n, cmp);
    for (i = 0; i < n; i++)
    {
        if (i == 0 || s[id[i]] != s[id[i - 1]])
            b[id[i]] = i;
        else b[id[i]] = b[id[i - 1]];
    }
    for (h = 1; h < n; h <<= 1)
    {
        for (i = 0; i < n; i++)
            head[i] = nexta[i] = -1;
        for (i = n - 1; i >= 0; i--)
        {
            if (id[i])
            {
                j = id[i] - h;
                if (j < 0) j += n;
                nexta[j] = head[b[j]];
                head[b[j]] = j;
            }
        }
        j = n - h;
        nexta[j] = head[b[j]];
        head[b[j]] = j;
        for (i = k = 0; i < n; i++)
            if (head[i] >= 0)
                for (j = head[i]; j >= 0; j = nexta[j])
                    id[k++] = j;
        for (i = 0; i < n; i++)
            if (i>0 && id[i] + h < n&&id[i - 1] + h < n&&b[id[i]] == b[id[i - 1]] && b[id[i] + h] == b[id[i - 1] + h])
                nb[id[i]] = nb[id[i - 1]];
            else
                nb[id[i]] = i;
        for (i = 0; i < n; i++)
            b[i] = nb[i];
    }
}

void GetHeight()
{
    int i, j, h; height[0] = 0;
    for (i = 0; i < n; i++)
        rank[id[i]] = i;
    for (h = 0, i = 0; i < n; i++)
    {
        if (rank[i] > 0)
        {
            j = id[rank[i] - 1];
            while (s[i + h] == s[j + h])++h;
            height[rank[i]] = h;
            if (h>0) --h;
        }
    }
}

int st[maxn], top;

int main()
{
    cin >> s;
    n = strlen(s);
    top = 0;
    SuffixSort();
    GetHeight();
    height[n] = 0;
    int best = n;
    st[top++] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        //cout << height[i] << " ";
        while (top != 0 && height[i] < height[st[top - 1]])
        {
            int val = height[st[top - 1]];
            top--;
            best = max(best, val * (top == 0 ? i : i - st[top - 1]));
        }

        if (top == 0 || height[i] >= height[st[top - 1]])
            st[top++] = i;
    }
    cout << best << endl;
    return 0;
}






*/