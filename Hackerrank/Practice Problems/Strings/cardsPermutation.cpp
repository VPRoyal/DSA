// Method 1 - Hackerrank editorial

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll mod = 1000*1000*1000+7;
 
vector<ll> fact;
int N, K;
vector<int> P;
 
struct BIT {
    vector<int> tree;
    void init() {
        tree = vector<int>(4*N, 0);
    }
    void upd(int idx, int val, int l, int r, int n) {
        if(idx < l || r < idx) return;
        if(l == r) {
            tree[n] = val;
            return;
        }
        int m = (l + r)>>1;
        upd(idx, val, l, m, 2*n);
        upd(idx, val, m + 1, r, 2*n + 1);
        tree[n] = tree[2*n] + tree[2*n + 1];
    }
    int quer(int a, int b, int l, int r, int n) {
        if(b < l || r < a) return 0;
        if(a <= l && r <= b) return tree[n];
        int m = (l + r)>>1;
        int L = quer(a, b, l, m, 2*n);
        int R = quer(a, b, m + 1, r, 2*n + 1);
        return L + R;
    }
} bit, sub;
 
int main() {
    fact.resize(500010);
    fact[0] = 1;
    for(int i = 1; i < 500010; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
 
    scanf("%d", &N);
    K = 0;
    P.resize(N);
    sub.init();
    for(int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        P[i]--;
        if(P[i] == -1) K++;
        sub.upd(i, 1, 0, N - 1, 1);
    }
 
    ll sum = 1LL * N * (N - 1) / 2;
    for(int i = 0; i < N; i++) {
        if(P[i] != -1) sum -= P[i], sub.upd(P[i], 0, 0, N - 1, 1);
    }
    sum = (sum % mod + mod) % mod;
 
    bit.init();
    ll ans = 0;
    ll tmp = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(P[i] == -1) {
            ll a = sum * fact[K - 1] % mod;
            ll b = tmp * fact[K - 1] % mod;
            ll c = K < 2? 0 : (1LL * K * (K - 1) / 2 % mod) * fact[K - 2] % mod * cnt % mod;
 
            ans += (a - b - c) * fact[N - i - 1] % mod, ans = (ans % mod + mod) % mod;
 
            cnt++;
        }
        else {
            bit.upd(P[i], 1, 0, N - 1, 1);
            tmp += sub.quer(P[i] + 1, N - 1, 0, N - 1, 1);
            tmp %= mod;
 
            ll a = fact[K] * P[i] % mod;
            ll b = fact[K] * bit.quer(0, P[i] - 1, 0, N - 1, 1) % mod;
            ll c = K == 0? 0 : fact[K - 1] * sub.quer(0, P[i] - 1, 0, N - 1, 1) % mod * cnt % mod;
 
            ans += (a - b - c) * fact[N - 1 - i] % mod, ans = (ans % mod + mod) % mod;
        }
    }
    cout << (ans + fact[K]) % mod;
}



// Method-2 

/*

#include <bits/stdc++.h>

using namespace std;

#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000
#define MOD 1000000007
#define long long long // for codeforces

template<typename T>
class BIT {
private:
  vector<T> bit;
  int n;
public:
  BIT(int _n) : n(_n) {
    bit = vector<T>(n+1, 0);
  }
  void add(int v, T a){ //0-indexed
    for(int x=v+1; x<=n; x += x&(-x)) bit[x] += a;
  }
  T sum(int v){ //0-indexed
    T ret=0;
    for(int x=v+1; x>0; x -= x&(-x)) ret += bit[x];
    return ret;
  }
};

int a[300005];
bool appear[300005];
long fact[300005];

int main(){
  int n;
  scanf("%d", &n);
  rep(i,n) scanf("%d", a+i);

  fill(appear, appear+n+1, false);
  rep(i,n) appear[a[i]] = true;
  vector<int> b; // numbers not appeared
  rep(i,1,n+1) if(!appear[i]) b.pb(i);
  // b is already sorted

  fact[0] = 1;
  rep(i,n) fact[i+1] = (i+1)*fact[i] %MOD;

  long m = b.size();
  long sumb = 0;
  for(auto x : b) sumb += x-1;
  sumb %= MOD;
  BIT<int> bit(n+1);
  long ans = fact[m];
  long k = 0; // # of slots(=0) already passed
  long pre = 0;
  rep(i,n){
    if(a[i]==0){
      long tmp = sumb * fact[m-1] %MOD
                - pre * fact[m-1] %MOD
                - ((m>=2) ? (m*(m-1)/2 %MOD * fact[m-2] %MOD * k %MOD) : (0));

      ans = (ans + tmp*fact[n-i-1]) %MOD;
      k++;
    }
    else {
      long tmp = (a[i]-1) * fact[m] %MOD
                - bit.sum(a[i]) * fact[m] %MOD
                - ((m>=1) ? ((long)(lower_bound(all(b), a[i]) - b.begin()) * k %MOD * fact[m-1] %MOD) : (0));

      ans = (ans + tmp*fact[n-i-1]) %MOD;
      bit.add(a[i], 1);
      pre = (pre + b.end() - lower_bound(all(b), a[i])) %MOD;
    }
  }

  ans %= MOD;
  if(ans < 0) ans += MOD;

  cout << ans << endl;

  return 0;
}





*/