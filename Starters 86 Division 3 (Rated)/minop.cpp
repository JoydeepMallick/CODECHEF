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

const int N = 1e6+5;
vll pfact[N];// max 1e6 computations
vll freq(N, 0);//set all to 0

void sieve_of_eratosthenes(int N)
{
    for(int i=2;i<N;i++)
    {
        if(pfact[i].size()==0)
        {
            for(int j=i;j<N;j+=i)
            pfact[j].pb(i);
        }
    }
}

void test(){
    int n, m;
    cin >> n >> m;
    vll a(n);
    read(a);
    /*
If all the Ai are already equal, the answer is 0. We need to solve for the case when they aren’t.

M can be 2 or more.

Notice that choosing X=2 sets every Ai to either 1 or 2.

Choosing X=3 after this sets everything to 1, since gcd(1,3)=gcd(2,3)=1 gcd(1,3)=gcd(2,3)=1.


So, it’s always possible to make everything equal within two moves. All we need to check is whether everything can be made equal in 1.

Suppose we are able to do this, and make all the array elements equal to YY in the end.
There are two possibilities here: either Y=1Y=1, or Y>1Y>1.





 Y = 1

We want to choose 2≤X≤M such that gcd(Ai,X)=1gcd(Ai,X)=1 for every Ai.

In particular, this means that XX cannot share a prime factor with any of the Ai; if it did, then the corresponding gcd wouldn’t be 11.

So, suppose we have a list of all the prime factors of all the Ai, say L.
We need to check if there’s an XX between 22 and MM that doesn’t have a prime factor in LL.
Notice that it’s enough to restrict ourselves to the case when XX is prime.

So, we simply need to check whether there’s any prime in the range [2,M] that isn’t in LL.
If the primes upto MM are precomputed (using a sieve), this is easy to do (given that you have LL in hand, of course).

Finally, we also need to discuss how to compute the list LL quickly, i.e, how to prime-factorize all the AiAi​ quickly.
The constraints are low enough that directly factorizing each number in O(Ai)O(Ai​

​) is probably fast enough, but there’s a faster way using the fact that Ai≤5⋅105Ai​≤5⋅105.

In the initial sieve we do to find prime numbers, also store one prime divisor of each number, let’s call it prm[x]prm[x] for xx.
Then, to prime factorize AiAi​:

    prm[Ai]prm[Ai​] is one prime factor.
    The next prime factor can be found by dividing prm[Ai]prm[Ai​] out of AiAi​ and again looking at the prmprm array, i.e, looking at prm[Aiprm[Ai]]prm[prm[Ai​]Ai​​].
    Repeat this while Ai>1Ai​>1.

Each division (at least) halves AiAi​, so this will take log⁡AilogAi​ steps.
This allows us to obtain all the prime factors of the AiAi​ in O(Nlog⁡M)O(NlogM) time.

Putting everything together, the solution for this case looks as follows:

    Quickly prime factorize all the AiAi​, either using the method outlined above or otherwise.
    Let LL be the list of all prime factors of all the AiAi​.
    Then, for each prime pp from 22 to MM:
        If pp is present in LL, continue on. This can be checked quickly using, say, binary search.
        If pp is not present in LL, then performing one operation with pp is valid, and you can break out immediately.

Note that as long as you break out immediately, this is fast enough even though there’s no constraint on the sum of MM across all tests.
This is because the list LL contains at most Nlog⁡MNlogM elements. So,

    If a valid prime is found, it’ll certainly be within Nlog⁡M+1NlogM+1 steps at most, each taking one binary search. This is not a problem.
    If no valid prime is found, then Nlog⁡MNlogM must exceed the number of primes from 11 to MM, which is approximately Mlog⁡MlogMM​ by the prime number theorem.
    This roughly gives us a lower bound on NN, something like N≥Mlog⁡2MN≥log2MM​.
    Since the sum of NN across all cases is bounded, we’re fine.





Y > 1

Suppose we’re able to choose an XX such that gcd⁡(Ai,X)=Ygcd(Ai​,X)=Y for every ii, and Y>1Y>1.

Notice that YY must be a factor of both XX and AiAi​ — in fact, YY must be a factor of every AiAi​.
This means YY must be factor of gcd⁡(A1,A2,…,AN)gcd(A1​,A2​,…,AN​), by definition of gcd⁡gcd.

In particular, if gcd⁡(A1,…,AN)=1gcd(A1​,…,AN​)=1, then such a YY cannot exist.
On the other hand, if gcd⁡(A1,…,AN)>1gcd(A1​,…,AN​)>1, then simply choosing X=gcd⁡(A1,…,AN)X=gcd(A1​,…,AN​) will also give us Y=gcd⁡(A1,…,AN)>1Y=gcd(A1​,…,AN​)>1, and we’ll be done!

Check both cases above to see if using one move is possible.
If both cases fail, then the answer is 22, using X=2X=2 and X=3X=3 as discussed above.

TIME COMPLEXITY

O(Nlog⁡2M)O(Nlog2M) per test case with a sieve upto 106106 as precomputation.

*/

    sort(all(a));
dbg(a);
    if(a[0] == a[n-1]) cout << 0 << endl;// all numners same 
    else{
        
        for(auto num : a){
            for(auto pf : pfact[num]){
                //iterate through all prime factors of num 
                freq[pf]++;
            }
        }

        int f = 0;
        fori(2, m+1){
            if(pfact[i][0] != i) continue; 
            if(freq[i] == 0 || freq[i] == n){
                f = i;
                break;
            }
        }
        
        // reinitialize freq array 
        fori(0, n){
            for(auto pf : pfact[a[i]]) freq[pf] = 0;
        }

        if(f) cout << 1 << "\n" << f << '\n';
        else cout << 2 << "\n" << m << " " << m-1 << "\n";

    }

}
/*
Note :-

Creating a 10^6 sized array many times will typically be heavier and require more time than creating it one time and reinitializing it repeatedly.

Creating a large array requires allocating a block of memory, which can take a non-trivial amount of time, especially if the array is very large. Repeating this process many times can result in a significant amount of overhead. On the other hand, reinitializing an existing array to all 0s can be done efficiently using a simple loop, with no need to allocate new memory.

Therefore, if you need to repeatedly use a large array and modify its contents, it is generally better to create it once and then reuse it, rather than creating a new array each time.

Hence we simply reinitialize freq content than recreating it everytime.

*/
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t = 1;//if test case is 1 only please comment out cin statement below
  cin >> t;
  auto t1 = std::chrono::high_resolution_clock::now();
  int temp = t;

  sieve_of_eratosthenes(N);


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


