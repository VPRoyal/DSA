// ----->>>>>> Method-1 <<<<<------------
#include <bits/stdtr1c++.h>
#define MAX 616
#define clr(ar) memset(ar, 0, sizeof(ar))
using namespace std;
const long long HMOD[] = {2078526727, 2117566807};
const long long BASE[] = {1572872831, 1971536491};
int n, m;
char str[2][MAX];
long long ar[4 * MAX * MAX];
long long P[2][MAX], H[2][2][MAX][MAX], R[2][2][MAX][MAX];
void generate(){
    int i, j, k, d;
    unsigned long long x;
    clr(H), clr(R);
    for (d = 0; d < 2; d++){
        for (P[d][0] = 1, i = 1; i < MAX; i++) P[d][i] = (P[d][i - 1] * BASE[d]) % HMOD[d];
    }
    for (d = 0; d < 2; d++){
        for (i = 0; i < 2; i++){
            for (j = 0; j < n; j++){
                for (k = j, x = 0; k < n; k++){
                    x = ((x * BASE[d]) + str[i][k] + 1007) % HMOD[d];
                    H[d][i][j][k] = x;
                }
            }
            for (j = n - 1; j >= 0; j--){
                for (k = j, x = 0; k >= 0; k--){
                    x = ((x * BASE[d]) + str[i][k] + 1007) % HMOD[d];
                    R[d][i][k][j] = x;
                }
            }
        }
    }
}
void simulate(){
    generate();
    long long val[2][2];
    int d, i, j, k, l, v;
    for (k = 0; k < 2; k++){
        for (i = 0; i < n; i++){
            val[0][0] = (R[0][k][0][i] * P[0][i + 1] + H[0][k ^ 1][0][i]) % HMOD[0];
            val[1][0] = (R[1][k][0][i] * P[1][i + 1] + H[1][k ^ 1][0][i]) % HMOD[1];
            for (j = i, d = k ^ 1; j < n; j++, d ^= 1){
                for (v = 0; v < 2; v++){
                    val[v][1] = ((val[v][0] * P[v][n - j - 1]) + H[v][d][j + 1][n - 1]) % HMOD[v];
                    val[v][1] = ((val[v][1] * P[v][n - j - 1]) + R[v][d ^ 1][j + 1][n - 1]) % HMOD[v];
                    val[v][0] = ((val[v][0] * BASE[v]) + str[d][j + 1] + 1007) % HMOD[v];
                    val[v][0] = ((val[v][0] * BASE[v]) + str[d ^ 1][j + 1] + 1007) % HMOD[v];
                }
                ar[m++] = (val[0][1] << 32) | val[1][1];
            }
        }
    }
}
int main(){
    int t, i, j, res;
    scanf("%d", &t);
    while (t--){
        m = 0;
        scanf("%d", &n);
        scanf("%s %s", str[0], str[1]);
        simulate();
        for (i = 0; i < 2; i++) reverse(str[i], str[i] + n);
        simulate();
        sort(ar, ar + m);
        res = 0, ar[m] = -1;
        for (i = 0; i < m; i++) res += (ar[i] != ar[i + 1]);
        printf("%d\n", res);
        ///fprintf(stderr, "%d = %d = %d\n", res, 2 * ((n * n) - n + 2), (2 * ((n * n) - n + 2)) - res);
    }
    return 0;




/* 

------>>>>> Method-2  <<<<<<<---------------


#include <bits/stdc++.h>

using namespace std;
#define PB push_back
#define MP make_pair
#define LL long long
#define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

template<class C> void mini(C& _a4, C _b4) { _a4 = min(_a4, _b4); }
template<class C> void maxi(C& _a4, C _b4) { _a4 = max(_a4, _b4); }

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<'='<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}

template<class T> ostream& operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto& vv : V) os << vv << ","; os << "]";
  return os;
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif

const int MAX = 611;
int n;
string t[2];
int P = 1e9 + 9;
int pp[MAX*2];
int hp[2][MAX];
int hs[2][MAX];
int MOD = (1ll<<61) - 1;
int razy(__int128 a, __int128 b){
  return (a * b) % MOD;
}
struct hh{
  vector<int> h;
  hh(){h.PB(0);}
  void add(char z){
    h.PB(h.back() + razy(z, pp[SZ(h)-1]));
    h.back() %= MOD;
  }
  int daj(int i,int j){
    return (h[2*j] - h[2*i+2] + MOD) % MOD;
  }
};
void test(){
  cin >> n >> t[0] >> t[1];
  unordered_set<int> secik;
  R(_,2){
    hh z[2];
    R(i,n){
      int pom = i&1;
      z[0].add(t[pom][i]);
      z[0].add(t[!pom][i]);
      z[1].add(t[!pom][i]);
      z[1].add(t[pom][i]);
    }
    R(i,n){
      R(j,2){
        hp[j][i+1] = razy(hp[j][i], P) + t[j][i] + razy(t[!j][i], pp[2*i+1]);
        hp[j][i+1] %= MOD;
      }
      R(j,2){
        hs[j][i+1] = razy(hs[j][i], P) + t[j][n-i-1] + razy(t[!j][n-i-1], pp[2*i+1]);
        hs[j][i+1] %= MOD;
      }
    }
    R(i,n)R(k,2){
      hs[k][n-i] = razy(hs[k][n-i], pp[2 * i]);
    }
    R(k,2)
      secik.insert(hs[k][n]);
    R(j,n)R(i,j)R(k,2){
      int hash = hp[k][i+1];
      hash += z[k ^ (i&1)].daj(i,j);
      hash += hs[k ^ (i&1) ^ (j&1)][n-j];
      secik.insert(hash%MOD);
    }
    reverse(ALL(t[0]));
    reverse(ALL(t[1]));
  }
  cout << SZ(secik) << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  cerr << fixed << setprecision(6);
  pp[0] = 1;
  R(i,MAX*2-1)pp[i+1] = razy(pp[i], P);
  int t;cin >> t;while(t--)test();
}
*/