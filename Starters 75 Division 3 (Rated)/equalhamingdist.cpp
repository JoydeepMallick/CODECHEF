/*
 __________________________
|  Written by silent_Joy  |
   ---------~u~---------  

*/
#include"bits/stdc++.h"
using namespace std;

/*____________________________________MACRO DEFINATIONS_______________________________________*/

#define ul unsigned long int // 0 to 2^32 - 1
#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvll vector<vector<long, long> >

//map macro
#define mii map<int, int>
#define mis map<int, string>
#define mss map<string, string>
#define msi map<string, int>

//pair macro
#define pii pair<int, int>
#define pis pair<int, string>
#define pss pair<string, string>

//priority queue
#define mxheap priority_queue<ll>
#define mnheap priority_queue<ll,vector<ll>,greater<ll>>

typedef char* ptr;

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end() 
#define allrev(a) a.rbegin(), a.rend()
#define endl "\n"
#define watch(x) cout << #x << " = " << x << endl //simple debugger 

//loop constructs shortened using macro defination
#define fori(a, n) for (ul i = a; i < (ul)n; i++)
#define forj(a, n) for (ul j = a; j < (ul)n; j++)
#define fork(a, n) for (ul k = a; k < (ul)n; k++)
//note in place of decrement please put negative values only
#define foridec(n, a, dec) for (ul i = n; i > (ul)a; i+=dec) 
#define forjdec(n, a, dec) for (ul j = n; j > (ul)a; j+=dec)
#define forkdec(n, a, dec) for (ul k = n; k > (ul)a; k+=dec)

#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*____________________________________CONSTANTS FREQUENTLY USED____________________________________*/

const int mod = 1000000007;//10^9+7
const ll PI   = 3.141592653589793238462;


/*_______________________________ FUNCTION DEFINATIONS ___________________________________*/


template <typename T, typename std::enable_if<std::is_integral<T>::value>::type* = nullptr>
bool isPowerOfTwo(T x)
{    
    return (x != 0) && ((x & (x - 1)) == 0);
}

template <typename T_all>//string,float,int,.... all types
bool isPalindrome(T_all s)
{
  string new_s;
  new_s = s;
  int n = len(new_s);
  fori(0,n/2)
  {
    if (new_s[i] != new_s[n - i - 1])
      return false;
  }
  return true;
}

template<typename T> void _do(T x){cerr << x << "\n";}
template<typename T, typename ...U> void _do(T x, U ...y){cerr << x << ", "; _do(y...);}
#define dbg(...) cerr << #__VA_ARGS__ << " = "; _do(__VA_ARGS__);

 // use the inbuilt function of C++ std::__gcd(x,y) (2 underscores)

ll lcm(ll x, ll y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS


/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/


ull binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ull modInverse(ull n, int p)
{
    return binpow(n, p - 2, p);
}

ull nCrModPFermat(ull n, int r, int p)
{
    if (n < r) return 0;
    if (r == 0) return 1;
    ull fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
  
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

void test(){
    ll n;
    string s1,s2;
    cin >> n >> s1 >> s2;
    /*
     *
     for each s1[i] == s2[i], 2 possiblities i.e. c[i] = 0 or 1

     but the moment s1[i] != s2[i]  we must find a j for which s1[j] == s2[i] and s2[j] == s1[i] i.e. 1,0 and 0,1

     else ans is 0.

     for each such pair possible permutations 0,1 and 1,0 , if pair count is x and total 0,1 or 1,0 count is  c then x = c/2 and combinations for those places is nCx

     Else those two places as in C in index i and j if one is 0 another must be 1 for above specific case , c[i] == c[j] is not possible so always alternate combinations needed.

    assume s1 =  1 1  1  1
    assume s2 =  0 0  0  0

    here possiblities are 1 1 0 0 , 1 0 1 0 where haming distance is 2.

    if we assume a a combination like 1 1 0 1 we can't equalize the haming distance hence we can notice that :-

    we always need a even no. of 0 and 1 for those postions where s1[i] != s2[i] provided the number of postions available is evenelse we know its never possible as mentioned earlier and we output a zero.

    HENCE OUR RESULT :-

    for s1[i] = s2[i] , it doesnt matter when we place 0 or 1 so each such postions contribute to 2 possiblites. Hence if the count of such possitions is p then possible combinations is 2^p

    now for the unequal bits provided the count is even we get nCx combinations.

    so total possible cobinations of desired c is       2^p(p > 0)   *   nCx(n > 0) if any one p or n is 0 in product replace it by one.

     */
    ll p = 0, c = 0;
    fori(0,n){
        if(s1[i] == s2[i]) p++;
        else c++;
    }
  // if c is odd then no array c can be created satisfying the conditions
    if(c%2) cout << 0 << endl;
    else cout << ( ( (c ? nCrModPFermat(c, c/2, mod) : 1) * (p ? binpow(2, p, mod) : 1) ) % mod ) << endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t = 1;//if test case is 1 only please comment out cin statement below
	cin >> t;
    auto t1 = std::chrono::high_resolution_clock::now();
        while(t--){
#ifndef ONLINE_JUDGE
              cout << "__________________________________________________________" << endl;
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

