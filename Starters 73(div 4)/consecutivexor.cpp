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

void test(){
    ll n;
    cin >> n;
    int a[n];
    int secondlast = 0;
    fori(0, n){
        cin >> a[i];
        if(i!=n-1) secondlast^=a[i];
    }
    /*
     * important property of xor :-
        1.  xor of 2 equal numbers is 0 i.e. a ^ a = 0
        2.  xor of a number and 0 equals that number i.e. a ^ 0 = a

        for array     3 2 2 3
            index     0 1 2 3
        if x = 3 for index 0 and 1, new array   0 1 2 3
        if x = 1 for index 1 and 2, new array   0 0 3 3
        if x = 3 for index 2 and 3, new array   0 0 0 0
        hence possible.

        we notice that we always select x as the value at index x so that we can surely predict the future value as 0


        for array   1 2 4
            index   0 1 2

        if x = 1 for index 1 and 0, array       0 3 4
        if x = 3 for index 2 and 3, array       0 0 7
        we notice that length of array is odd, lets keep 7 intact and convert the rest even elements into 7
        if x = 7 for index 0 and 1, array       7 7 7

        hence possible


APProach :-

assume an odd array    p  q  r
if x = p,            0   p^q   r
if x = q,           0   0   p^q^r

hence even number of 0 is always attained, which can be converted to the last xor of all elements

hence for no. of elements to be ODD its always possible


for even array, if after having xor n-2 times in the above fashion we find that last two elements are equal then only yes, else a no

assume initial array as  r1 r2 r3 ..... rn p  q

after n-2 xor operations --

0 0 0 0 .....  p'  q

here p' = r1^r2^....^rn^p

if p' and q are same then only true.

this can also be interpreted as xor of all elements if 0 possible else not possible. 
     */
    if(n%2) yes;
    else if(a[n-1] == secondlast) yes;
    else no;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int t = 1;//if test case is 1 only please comment out cin statement below
	cin >> t;
    auto t1 = std::chrono::high_resolution_clock::now();
        while(t--)
            test();
    auto t2 = std::chrono::high_resolution_clock::now();

#ifndef ONLINE_JUDGE
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    cout << ms_double.count() << "ms\n";
#endif
	return 0;
}

