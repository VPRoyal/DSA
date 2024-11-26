#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define FOR(a,b,c) for (int a=b,_c=c;a<=_c;a++)
#define FORD(a,b,c) for (int a=b;a>=c;a--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; ++i)
#define REPD(i,a) for(int i=(a)-1; i>=0; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn=200007;

int c[maxn],SA[maxn],RA[maxn],tSA[maxn],tRA[maxn],len;
int PLCP[maxn],LCP[maxn],pre[maxn];
char T[maxn];
int fRA(int v){return(v<=len?RA[v]:0);}

void sort(int k){
    int t,sum,i,maxi=max(300,len);
    FOR(i,0,maxi) c[i]=0;
    FOR(i,1,len) {c[fRA(SA[i]+k)]++;}
    for(i=sum=0; i<=maxi; i++){
        t=c[i];
        c[i]=sum;
        sum+=t;
    }
    FOR(i,1,len) tSA[++c[fRA(SA[i]+k)]]=SA[i];
    FOR(i,1,len) SA[i]=tSA[i];
}

void constructSA(){
    int r;
    FOR(i,1,len) RA[i]=T[i], SA[i]=i;
    for(int k=1; k<len; k<<=1){
        sort(k); sort(0);
        r=tRA[SA[1]]=1;
        FOR(i,2,len)
            tRA[SA[i]]=(RA[SA[i]]==RA[SA[i-1]] && fRA(SA[i]+k)==fRA(SA[i-1]+k))?r:++r;
        FOR(i,1,len) RA[i]=tRA[i];
    }
    int l=0;
    pre[SA[1]]=-1;
    FOR(i,2,len) pre[SA[i]]=SA[i-1];
    FOR(i,1,len){
        if(pre[i]==-1){PLCP[i]=0; continue;}
        while(i+l<=len && pre[i]+l<=len && T[i+l]==T[pre[i]+l]) l++;
        PLCP[i]=l;
        l=max(l-1,0);
    }
    FOR(i,1,len) LCP[i]=PLCP[SA[i]];
}

int lastPos[26];
vector<int> jmp[maxn];

void constructJump(){
    for(int i=0; i<26; ++i) lastPos[i]=len+1;
    for(int i=len; i>=1; --i){
        lastPos[T[i]-'a'] = i;
        jmp[i].clear();
        for(int v=0; v<26; ++v) if(lastPos[v]<=len) jmp[i].pb(lastPos[v]);
        jmp[i].pb(len+1);
        sort(jmp[i].begin(), jmp[i].end());
    }
}


ll sum[27][maxn];
ll p[maxn];
void init(){
    for(int i=1; i<=100000; ++i) p[i]=1;
    for(int j=1; j<=26; ++j){
        for(int i=1; i<=100000; ++i){
            p[i] = p[i]*i%oo;
            sum[j][i]=sum[j][i-1]+p[i];
        }
    }
}

ll cal(int start, int finish){
    if(finish < start) return 0;
    int u = start;
    ll res = 0;
    for(int i=1; i<sz(jmp[start]) && u<=finish; ++i){
        int v = jmp[start][i];
        if(v > finish+1) v = finish+1;
        res = (res + (sum[i][v-start] - sum[i][u-start]) + oo)%oo;
        u = v;
    }
    return res;
}

void solve(){
    ll res = 0;
    for(int i=1; i<=len; ++i){
        int start=SA[i];
        res = (res - cal(start, start + LCP[i] - 1) + oo)%oo;
        res = (res + cal(start, len))%oo;
    }
    cout<<res<<endl;
}

int main(){

//    freopen("input.txt","r",stdin);
    int nTest;
    scanf("%d",&nTest);
    init();
    while(nTest--){
        scanf("%s",T+1); len=strlen(T+1);
        constructSA();
        constructJump();
        solve();
    }
}