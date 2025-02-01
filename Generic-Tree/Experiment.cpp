  /*-------------> _Captain <--------------*/
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,mmx,abm,avx,avx2,fma")
#define nline "\n";
using ll = long long;
using ull = unsigned long long;
using ld = long double;  
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define range(a) for (auto &it : a) 
#define flp(i,a,b) for(ll i=a;i<b;i++)
#define flpb(i,a,b) for(ll i=a;i>=b;i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define umap unordered_map
#define uset unordered_set
#define popcount(x) __builtin_popcountll(x)
#define bit(x) (1LL << (x))
#define clz(x) __builtin_clzll(x)
#define ctz(x) __builtin_ctzll(x) 
#define F first
#define S second
#define B begin()
#define E end()  
#define rB rbegin()
#define rE rend()
#define SUM(x) accumulate(x.B,x.E,0ll)
#define maxi(x) *max_element(x.B,x.E)
#define mini(x) *min_element(x.B,x.E)
#define YES cout<<"YES"<<"\n";
#define NO cout<<"NO"<<"\n";
#define Yes cout<<"Yes"<<"\n";
#define No cout<<"No"<<"\n"; 
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vvvi vector<vvi>
#define pii pair<ll,ll>
#define vpii vector<pii>
#define vs vector<string>
#define vd vector<ld>


const ll MOD=1000000007;
const ll MOD1=998244353;
const ll MOD2=10000000002065383;

template <typename T> void read_vec(vector<T>& v) { for (auto& x : v) {std::cin >> x;}}
template <typename T> void print_vec(const vector<T>& v) { for(const auto& x : v) { std::cout << x << " ";} std::cout << '\n';}
 
/*------------------------------------------------  DEBUGGING-FRAME END -------------------------------------------------------*/ 

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif 

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(pair<ll,ll> t){cerr<<t.F<<","<<t.S;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*------------------------------------------------  DEBUGGING-FRAME END -------------------------------------------------------*/ 

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a,b));} 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
void test(int t) {cerr << "Case #" << t << "\n";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precompute_fact_ifact(ll max_n, ll mod, ll *fact, ll *ifact) { fact[0] = 1;for (ll i = 1; i <= max_n; i++) {fact[i] = (fact[i - 1] * i) % mod; } ifact[max_n] = mminvprime(fact[max_n], mod); for (ll i = max_n - 1; i >= 0; i--) {ifact[i] = (ifact[i + 1] * (i + 1)) % mod;}}
/*--------------------------------------------------------------------------------------------------------------------------*/




bool doTestcasesExist=1;
   doTestcasesExist=0;
void solve(){
     // Generic Tree
     


 


 

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    #ifndef ONLINE_JUDGE
        freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
        freopen("Error.txt", "w", stderr);
    #endif 
    auto start1 = high_resolution_clock::now(); 


    if(doTestcasesExist){
        ll tc;
        cin>>tc;
        for(ll testcase=0;testcase<tc;testcase++){
            test(testcase);
            solve();
        }
    }else{
        solve();
    }
    
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
        cerr << "Time: " << duration . count() / 1000 << endl;
    #endif
    return 0; 
}
     /*-------------> _Captain <--------------*/

 