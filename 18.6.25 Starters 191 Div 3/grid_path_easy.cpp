/*
   _________________________
   | Written by silent_Joy |
     ---------~u~---------  
*/

#include"bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt") 
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") //intel pentium porcessors released post 2020 support avx2, unfortunately my Pentium 2020M doesn't 
using namespace std;

/*_____________________________ MACRO DEFINATIONS ____________________________*/

using ll = long long; // -2^63 to 2^63 - 1
using ull = unsigned long long; // 0 to 2^64 - 1
using ld = long double; // 12 bytes (12*8 bits)
//vector macro
using vll = vector<ll>;
using vvll = vector< vector<ll> >;
using vpll = vector<pair<ll,ll>>;
//map macro
using mll = map<ll, ll>;
//pair macro
using pll = pair<ll, ll>;
//priority queue
#define mxheap priority_queue<ll>
#define mnheap priority_queue<ll,vector<ll>,greater<ll>>

typedef char* ptr;

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end() 
#define allrev(a) a.rbegin(), a.rend()
#define endl "\n"
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fi first 
#define se second 

/*use stoll instead of stoi */

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()
#define UID(a,b) uniform_int_distribution<int>(a,b)(rng)
//loop constructs shortened using macro defination
#define fori(a, n) for (ull i = a; i < (ull)n; i++)
#define forj(a, n) for (ull j = a; j < (ull)n; j++)
#define fork(a, n) for (ull k = a; k < (ull)n; k++)
//some alternatives but I lousily prefer the above, trying to shift...
#define ffor(i,a,b) for(ll i=(a); i < (b); i++)
#define rfor(i,a,b) for(ll i=(a); i > (b); i--)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*______________________ COMMON FUNCTION DEFINATIONS _________________________*/

ull lcm(ull x, ull y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS using inbuilt function __gcd(x,y)

// This is a template function that takes in two arguments, a and b, and updates the value of a to be the minimum of the two. It returns true if a was updated, and false otherwise.
template<class T> bool umin(T& a, T b){return a>b?(a=b,1):0;}
// This is similar to umin, but updates a to be the maximum of the two values.
template<class T> bool umax(T& a, T b){return a<b?(a=b,1):0;}

template<typename T>
void read(vector<T>& v) {for (auto& x : v) {cin >> x;}}
template<typename T>
void print(const vector<T>& v) {for (auto x : v) { cout << x << " ";} cout << endl;}

/*_________________________________ DEBUGGER ________________________________*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _do() {cerr << " \n";}

template <typename T, typename... V>
void _do(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _do(v...);}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << __func__ << "(),line " << __LINE__ << ": " <<  #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
#else
#define dbg(...)//arrays can't be debugged with this, use std::array instead
#endif

/*_______________________ CONSTANTS FREQUENTLY USED ________________________*/
const int mod=1e9+7;//10^9+7
const int inf=1e9;
const ll INF=1e18;
const ld PI = 3.141592653589793238462;
/*________ ADDITIONAL FUNCTION DEFINATIONS NEEDED FOR CURRENT CODE ________*/ 



/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

void test(){
    int n, q;
    cin >> n >> q;
    string s0, s1;
    cin >> s0;
    cin >> s1;
    while(q--){
        int x, y;
        cin >> x >> y;
    }
    int s0cnt1 = count(s0.begin(), s0.end(), '1');
    int s1cnt1 = count(s1.begin(), s1.end(), '1');

    if(s0cnt1 + s1cnt1 < (n+1)) {
        cout << -1 << endl;
        return;
    }
    
    //s0 pref 0
    int pref0[200005] = {0};
    pref0[0] = (s0[0] == '0');
    fori(1, n){
        pref0[i] = pref0[i-1] + (s0[0] == '0');
    }
    
    // s1 suf 0 
    int suf0[200005] = {0};
    suf0[n-1] = (s1[n-1] == '0');
    for(int i = n-2; i >= 0; i--){
        suf0[i] = suf0[i+1] + (s1[i] == '0');
    }
    
    //one 1 from least cost right goes to left extreme in s0 
    //parallely one 1 from least cost left goes to right extreme in s1
    int i = 0, j = n-1;
    int total1placed = 0;
    int skipplaced = 0;
    int s0cost = 0, s1cost = 0;
    while(total1placed < (n+1)){
        if(i < n){
            while(s0[i] != '1') i++;
            s0cost += pref0[i] - skipplaced;
            i++;
            total1placed++;
        }
        if(j >= 0){
            while(s1[j] != '1') j--;
            s1cost += suf0[j] - skipplaced;
            j--;
            total1placed++;
        }
        skipplaced++;
    }
    cout << s0cost + s1cost << endl;
    
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t = 1;//if test case is 1 only please comment out cin statement below
  cin >> t;
  auto t1 = std::chrono::high_resolution_clock::now();
  int temp = t;
  while(t--){
#ifndef ONLINE_JUDGE
    cout << "________________________ TEST CASE #" << temp-t << " ________________________" << endl;
#endif
    test();
  }
  auto t2 = std::chrono::high_resolution_clock::now();

#ifndef ONLINE_JUDGE
  std::chrono::duration<double, std::milli> ms_double = t2 - t1;
  cout << ms_double.count() << "ms\n";
#endif
  return 0;
}



