// Method-1 -- Fully workable
#include <bits/stdc++.h>
using namespace std;

inline void wssert(bool b) { if(!b) exit(0); }

const string BAD = "-1";

const int MAXN = 2e5;
const int MAXM = 2e5;
const int MAXL = MAXN * 2 + MAXM * 2 + 20;
int N;
char A[MAXN];
int M;
char B[MAXM];
int L;
char V[MAXL];
int S;

int P[MAXL]; // length of palindrome - 1 / 2
int C[MAXL];

void manacher() {
    int c = 0, r = 0;
    memset(P, 0, sizeof(P));
    for(int i = 0; i < L; ) {
        assert(i - P[i] >= 0);
        assert(i + P[i] < L);
        assert(r == c + P[c]);
        assert(i >= c);
        assert(r >= i + P[i]);
        assert(i == c || r > i + P[i]);
        if(i == c) {
            assert(r == i + P[i]);
            if(i - P[i] - 1 >= 0 && i + P[i] + 1 < L && V[i - P[i] - 1] == V[i + P[i] + 1]) {
                P[i] ++;
                assert(i - P[i] >= 0);
                assert(i + P[i] < L);
            } else {
                i++;
                assert(P[i] == 0);
                assert(i - P[i] >= 0);
                assert(i == L || i + P[i] < L);
            }
       } else {
            assert(i > c);
            assert(r > i + P[i]);
            assert(c - P[c] >= 0);
            assert(c - (i - c) >= 0);
            int v = min(P[c - (i - c)], r - i);
            assert(v >= P[i]);
            if(v > P[i]) {
                P[i] = v;
                assert(i - P[i] >= 0);
                assert(i + P[i] < L);
            } else if (v == r - i) {
                assert(false);
            } else {
                i++;
                assert(P[i] == 0);
                assert(i - P[i] >= 0);
                assert(i == L || i + P[i] < L);
            }
        }
        if(i == L) break;
        if(i + P[i] >= r) {
            c = i;
            r = i + P[i];
        }
        assert(i - P[i] >= 0);
        assert(i + P[i] < L);
    }
}

#define REP(i, n) for(int i = 0; i < int(n); i++)
int gap;
int sa[MAXL], pos[MAXL], tmp[MAXL], lcp[MAXL];

bool sufCmp(int i, int j)
{
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < L && j < L) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
    REP(i, L) sa[i] = i, pos[i] = V[i];
    for (gap = 1;; gap *= 2)
    {
        sort(sa, sa + L, sufCmp);
        REP(i, L - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        REP(i, L) pos[sa[i]] = tmp[i];
        if (tmp[L - 1] == L - 1) break;
    }
}

void buildLCP()
{
    for (int i = 0, k = 0; i < L; ++i) if (pos[i] != L - 1)
    {
        for (int j = sa[pos[i] + 1]; V[i + k] == V[j + k];)
            ++k;
        lcp[pos[i]] = k;
        if (k)--k;
    }
}

string process(int l, int c) {
    string res;
    for(int i = l; i < c; i++) {
        if(V[i] != 124) res += V[i];
    }
    for(int i = c; i >= l; i--) {
        if(V[i] != 124) res += V[i];
    }
    return res;
}

string go() {
    manacher();
    for(int i = 0; i < L; i++) {
        assert(!(i - P[i] - 1 >= 0 && i + P[i] + 1 < L && V[i - P[i] - 1] == V[i + P[i] + 1]));
        //for(int j = 0; j <= P[i]; j++) assert(V[i - j] == V[i + j]);
    }
    memset(C, 0, sizeof(C));
    for(int i = 0; i < L; i++) {
        C[i - P[i]] = max(C[i - P[i]], i);
    }
    for(int i = 1; i < L; i++) {
        C[i] = max(C[i], C[i - 1]);
    }
    buildSA();
    buildLCP();
    for(int i = 0; i < L; i++) {
        //cerr << (V + sa[i]) << '\n';
    }
    for(int i = 0; i + 1 < L; i++) {
        //for(int j = 0; j < lcp[i]; j++) assert(V[sa[i] + j] == V[sa[i + 1] + j]);
        assert(V[sa[i] + lcp[i]] < V[sa[i + 1] + lcp[i]]);
    }
    assert(V[sa[N + M]] == 123);
    int p[2] = {-1, -1};
    int l[2] = {0, 0};
    pair<int, int> res (0, 0);
    for(int i = 0; i < N + M; i++) {
        assert(V[sa[i]] < 123);
        bool d = (sa[i] >= S);
        p[d] = sa[i];
        l[d] = L;
        if(p[!d] != -1) {
            int match = l[!d];
            assert(match % 2 == 0);
            //cerr << p[!d] << ' ' << p[d] << ' ' << match << '\n';
            if(match) res = max(res, make_pair(C[sa[i] + match - 1] - sa[i], -i));
        }
        if(i + 1 < L) l[0] = min(lcp[i], l[0]), l[1] = min(lcp[i], l[1]);
    }
    p[0] = p[1] = -1;
    l[0] = l[1] = -1;
    for(int i = N + M - 1; i >= 0; i--) {
        bool d = (sa[i] >= S);
        p[d] = sa[i];
        l[d] = L;
        if(p[!d] != -1) {
            int match = l[!d];
            assert(match % 2 == 0);
            if(match) res = max(res, make_pair(C[sa[i] + match - 1] - sa[i], -i));
        }
        if(i > 0) l[0] = min(lcp[i - 1], l[0]), l[1] = min(lcp[i-1], l[1]);
    }
    //cerr << res << '\n';
    if(res.first == 0) return BAD;
    return process(sa[-res.second], sa[-res.second] + res.first);
}

int main() {
    int Q; cin >> Q;
    while(Q --> 0) {
        cin >> A >> B;
        N = strlen(A), M = strlen(B);
        L = 0;
        for(int i = 0; i < N; i++) {
            V[L++] = A[i];
            V[L++] = 124;
        }
        V[L++] = 123;
        V[L++] = 125;
        S = L;
        for(int i = M - 1; i >= 0; i--) {
            V[L++] = B[i];
            V[L++] = 124;
        }
        V[L] = 0;
        assert(L == 2 * N + 2 * M + 2);
        cout << go() << '\n';
    }
    return 0;
}






/* ------->>>>>> Method-2 -- Not full operational. Getting TL. <<<<<-----------


#include <bits/stdc++.h>

using namespace std;
void addPalindrome(string& maxPalindrome, string newString){
    int nl=newString.size();
    if(nl<2) return;
    cout<<newString<<endl;
    if(newString.size() > maxPalindrome.size()) maxPalindrome=newString;
    else if(newString.size()==maxPalindrome.size() && newString<maxPalindrome) maxPalindrome=newString;
}
string maxPalindrome(string a, string b){
    int len1=a.length(), len2=b.length();
    string palindromeString="";
    vector<vector<int>> freq1(26), freq2(26);
    // Making frequency array for each of them
    for(int i=0; i<max(len1,len2); i++){
        if(i<len1) freq1[a[i]-'a'].push_back(i);
        if(i<len2) freq2[b[i]-'a'].push_back(i);
    }

    // Finding palindromes for a,b
    for(int i=0;i<len1;i++){
        char c=a[i];
        for( int j:freq2[c-'a']){
            int k=i, l=j;
            // For Optimization
            if((len1-i+j+1)<palindromeString.size()) break;

            string first, second, added;
            while(true){
                if(k==len1&&l>=0){
                    added=first+b[l]+second;
                    addPalindrome(palindromeString, added);
                    break;
                }else if(l<0&&k<len1){
                    added=first+a[k]+second;
                    addPalindrome(palindromeString, added);
                    break;
                }else if(l<0&&k>len1-1) break;
                if(a[k]==b[l]){
                    first.push_back(a[k]);
                    second=b[l]+second;
                    added=first+second;
                    addPalindrome(palindromeString, added);
                }else{
                    added=first+a[k]+second;
                    addPalindrome(palindromeString, added);
                    added=first+b[l]+second;
                    addPalindrome(palindromeString, added);
                    break;
                }
                k++;
                l--;
            }
        }
    }
    // For Optimization
    if(a==b) return palindromeString;

    // Finding palindromes for reverse a,b i.e. b,a
    for(int i=0;i<len2;i++){
        char c=b[i];
        for( int j:freq1[c-'a']){
            int k=i, l=j;
            // For Optimization
            if((len2-i+j+1)<palindromeString.size()) break;
            string first, second, added;
            while(true){
                if(k==len2&&l>=0){
                    added=first+a[l]+second;
                    addPalindrome(palindromeString, added);
                    break;
                }else if(l<0&&k<len2){
                    added=first+b[k]+second;
                    addPalindrome(palindromeString, added);
                    break;
                }else if(l<0&&k==len2) break;
                if(b[k]==a[l]){
                    first.push_back(b[k]);
                    second=a[l]+second;
                    added=first+second;
                    addPalindrome(palindromeString, added);
                }else{
                    added=first+b[k]+second;
                    addPalindrome(palindromeString, added);
                    added=first+a[l]+second;
                    addPalindrome(palindromeString, added);
                    break;
                }
                k++;
                l--;
            }
        }
    }

    return palindromeString;
}
int main(){
    int n;
    cin>>n;
    while(n--){
    string a, b;
    cin >> a >> b;
    string ans=maxPalindrome(a,b);
    cout<<"Final result: "<< ans<<endl;
    }
return 0;
}

*/