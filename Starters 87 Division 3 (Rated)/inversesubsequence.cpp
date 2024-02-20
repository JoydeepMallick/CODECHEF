/*
   __________________________
   |  Written by silent_Joy  |
   ---------~u~---------  
   */
#include"bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
/* #pragma GCC target("bmi,bmi2,lzcnt,popcnt") */
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") //intel pentium porcessors released post 2020 support avx2, unfortunately my Pentium 2020M doesn't 
using namespace std;

/*______________________MACRO DEFINATIONS______________________*/

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

//loop constructs shortened using macro defination
#define fori(a, n) for (ull i = a; i < (ull)n; i++)
#define forj(a, n) for (ull j = a; j < (ull)n; j++)
#define fork(a, n) for (ull k = a; k < (ull)n; k++)
//some alternatives but I lousily prefer the above, trying to shift...
#define ffor(i,a,b) for(ll i=(a); i < (b); i++)
#define rfor(i,a,b) for(ll i=(a); i > (b); i--)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*_________________CONSTANTS FREQUENTLY USED__________________*/
const int mod=1e9+7;//10^9+7
const int inf=1e9;
const ll INF=1e18;
const ld PI = 3.141592653589793238462;
const int MOD = 998244353;
/*__________________ FUNCTION DEFINATIONS _____________________*/


ull lcm(ull x, ull y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS using inbuilt function __gcd(x,y)

// This is a template function that takes in two arguments, a and b, and updates the value of a to be the minimum of the two. It returns true if a was updated, and false otherwise.
template<class T> bool umin(T& a, T b){return a>b?(a=b,1):0;}
// This is similar to umin, but updates a to be the maximum of the two values.
template<class T> bool umax(T& a, T b){return a<b?(a=b,1):0;}

template<typename T>
void read(vector<T>& v) {for (auto& x : v) {cin >> x;}}

template<typename T>
void read(T arr[], int n) { for (int i = 0; i < n; i++) { cin >> arr[i];}}

template<typename T>
void print(const vector<T>& v) {for (auto x : v) { cout << x << " ";} cout << endl;}

template<typename T>
void print(const T arr[], int n) {for (int i = 0; i < n; i++) {cout << arr[i] << " ";}cout << endl;}

/*__________________________ DEBUGGER _________________________*/

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
#define dbg(...) cerr <<"JOY_DBG active :- " <<  #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
#else
#define dbg(...)//arrays can't be debugged with this, use std::array instead
#endif

/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

ull modpow(int n, int M){
    ull ans = 1;
    while(n--){
        ans = (ans << 1)%M;
    }
    return ans;
}

void test(){
    int n;
    cin >> n;
    vector<int> a(n);
    read(a);
    //count number of index involved in inversions and 2^(n-indexofinversion) is answr if inversion exist else 2^n-1  
    //assume 4 2 5 3 6 1    inversions are   4,2  4,3   4,1   5,3  5,1   3,1   6,1  
/*

An index ii is part of an inversion iff:

    There exists an index j<ij<i such that Pj>PiPj​>Pi​; or
    There exists an index j>ij>i such that Pi>PjPi​>Pj​

That means that index ii is not part of any inversion iff Pi>PjPi​>Pj​ for every j<ij<i, and Pi<PjPi​<Pj​ for every j>ij>i.
In other words, Pi=max⁡(P1,P2,…,Pi)Pi​=max(P1​,P2​,…,Pi​) and Pi=min⁡(Pi,Pi+1,…,PN)Pi​=min(Pi​,Pi+1​,…,PN​).

By precomputing prefix maximums and suffix minimums, this can be checked for each index in O(1)O(1).

Now, we know exactly which indices must be included in any valid subsequence SS.
Each of the other indices may be included or not; they don’t affect the inversion count.

So, if there are kk ‘free’ indices, the number of subsequences is 2k2k.
Note that there’s a single edge-case here: if k=Nk=N, then the answer is 2k−12k−1 instead, since the empty sequence will be counted in 2k2k and we don’t want that.

*/
    vector<int> prefMax(n);
    vector<int> suffMin(n);
    prefMax[0] = 0;// so start index is 0
    suffMin[n-1] = n+1; // so end index is anything more than n 
    
    for(int i = 1; i < n; i++) prefMax[i] = max( prefMax[i-1], a[i-1] );
    for(int i = n-2; i >= 0; i--) suffMin[i] = min( suffMin[i+1], a[i+1] );
    dbg(a);
    dbg(prefMax, suffMin);

/* if(prefMax[i] < a[i] < suffMin[i]) then it is not an inversion index 

   assume    5  4  1  2  3  6   7   prefMax        [0,.......... ]   suffMin       [............BIGnumthan_n]

    prefMax [0, 5, 5, 5, 5, 5, 6]
    suffMin [1, 1, 2, 3, 6, 7, 9999]

    hence values at non inversion indices in a are  4,6,7 since they were greater than its max predecessor and lesser than its min successor hence it is normal non inversed form for any index combo.  
*/
    int removableindex = 0;
    fori(0,n){
        if(prefMax[i] < a[i] && a[i] < suffMin[i]) removableindex++;
    }

    ull ans = (1ull * modpow(removableindex, MOD) )%MOD;
    if(removableindex == n) ans--;
    
    cout  << ans << endl;
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


