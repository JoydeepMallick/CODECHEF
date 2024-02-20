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

void test(){
    ll n,x;
    cin >> n >> x;
    vll a(n);
    read(a);
    /*
    in or operation if any bit is one then both the result will become 1 in or operation

    we need to avoid such bits but we also need to maximie y 

    we need to check all bits in number which are not equal in all numbers in a 

    we have 2^30 so 30 bit places at max.

    --------------------------------------------------------
    PROBLEM:

You’re given an array AA containing at least two distinct elements, and an integer XX.

For an integer 0≤Y≤X0≤Y≤X, define the array BB as Bi=Ai∣YBi​=Ai​∣Y.
Find the largest YY such that BB consists of at least two distinct elements.
EXPLANATION:

Since the operation we’re dealing with is bitwise OR, it helps to look at things bit-by-bit.

First, a useful definition: we say a bit bb is set in the binary representation of integer xx if the binary representation of xx contains 2b2b.
For example, 9=(1001)2=20+239=(1001)2​=20+23 has bits 00 and 33 set, while bits 1,2,4,5,6,…1,2,4,5,6,… are not set.

Suppose we pick a YY and compute the array BB, and there are two unequal elements; say Bi≠BjBi​​=Bj​.
Then, in particular the binary representation of BiBi​ and BjBj​ must differ.
That is, there must exist a bit bb which is set in the binary representation of BiBi​ but not in BjBj​, or vice versa.

Without loss of generality, let’s say bb is set in BiBi​ and unset in BjBj​.
Then, we can observe the following:

    YY cannot have bit bb set (otherwise it would be set in Bj=Aj∣YBj​=Aj​∣Y)
    This means AiAi​ must’ve had bit bb set, and AjAj​ must’ve had it unset.

This tells us that for any valid YY, there will exist a bit bb such that:

    bb is unset in YY,
    Some element of AA has this bit set, and
    Some element of AA has this bit unset

Conversely, any YY that has such a bit bb can easily be seen to satisfy the condition.

So, let’s fix the value of bb and try to find the largest YY we can with respect to it; call this YbYb​.
The answer is the maximum value of YbYb​ across all bb.

Note that if bb is such that:

    Every element of AA has bb set; or
    Every element of AA has bb unset

then bb must be ignored, as per our rules above.
For a fixed bb, this can easily be checked in O(N)O(N) by iterating across all the elements.

Now the question is, how to find YbYb​ for a fixed bb?
That can be done greedily.

    Iterate over bits from largest to smallest, i.e, from 2929 down to 00.
    Initially, let Yb=0Yb​=0.
    Then, when processing bit ii,
        If i=bi=b, do nothing. This will ensure that YbYb​ doesn’t have bit bb set, as required.
        Otherwise, if Yb+2i≤XYb​+2i≤X, add 2i2i to YbYb​.
        This way, we ensure that we never exceed XX, while also making YbYb​ as large as possible.

So, for each bb:

    We first check whether it is possibly valid, i.e, some element of AA has it set and some other element has it unset.
    This is done in O(N)O(N).
    If it’s valid, we construct YbYb​ using the above algorithm. This is done in O(30)O(30).

Since we do this for each bit from 00 to 2929, the overall runtime is O(30⋅N+302)O(30⋅N+302) which is good enough.
TIME COMPLEXITY

O(30⋅N+302)O(30⋅N+302) per test case.
    */
dbg(a);
    ll res = 0;
    fori(0,30){ // < 2 ^ 30 
        ll cnt = 0;
        for(auto num : a){
            if(num & (1ll << i)){
                //if ith bit of number is on increase cnt 
                cnt++;
            }
        }
        //if all the bits were either 0 or 1 then no effective change with OR operation since all bits behavior will be similar leading to no 2 distinct number creation 
        if(cnt == 0 || cnt == n) continue;//discarded bit 
        
        //if loop accesses this portion it means current is valid bit 
        ll temp =  0;
        for(ll j = 29; j >= 0; j--){
            if(j==i) continue; //turn of the current bit and turn on others one by one and check wheter the max number obtained(since we started from 2^29 to smaller values) is less equal to x 
            ll tempAdd = 1ll << j;
            if(temp + tempAdd > x) continue;

            temp += tempAdd;//update temp if jth on bit can be placed safely
        }

        res = max(res, temp);// we create all possile numbers by turning off one valid bit and turning all others by maintaining the fact that it is always less than equal to x and the max of all possible combination is the maximum possible answer.

    }
    cout << res << endl;
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


