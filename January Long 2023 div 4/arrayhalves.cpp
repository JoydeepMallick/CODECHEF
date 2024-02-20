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
  ll n;//since 2*n hence unsigned long may be enough but not int as 2^16 but we need at least till 2^18
  cin >> n;
  ll a[2*n];
/* min of 2nd half = n;//its a permutation from 1 to n hence its obvious */
/* max of first half = n-1 */
  vll unwanted1st,unwanted2nd;
  fori(0,2*n){
    cin >> a[i];
    if(i < n && a[i] > n)  unwanted1st.push_back(i);
    if(i >= n && a[i] <= n) unwanted2nd.push_back(i);
  }
  /*
   Key observation :-

   as all array elements are a permutation
   and max of 1st half < min of 2nd half

   we can simply infer that : -
      * first half contains first n small elements
      * 2nd half contains n largest elements 
  
   If this above condition holds, then only a good array is possible.

   Hence, we need to check the above observations keeping in mind that any possible combination is allowed but condition must hold.


Solution :- 

 for the array 6 5 4 3 2 1
steps :-
          6 5 3       4 2 1
          6 5 3       2 4 1
          6 5 3       2 1 4

          6 3 5       2 1 4
          6 3 2       5 1 4
          6 3 2       1 5 4

          3 6 2       1 5 4
          3 2 6       1 5 4
          3 2 1       6 5 4

  It can be proved that no other process is shorter than 9 steps

  We observe that we here we try to shift the unwanted elements in 2nd half to the first half and this in order to be done in most efficient way by shifting all unwanted elements in 2nd half by one step forward. (can also be done in reverse order such that all unwanted elements in first half are moved by one step to right one by one and again )

  This wont be our proceeding always note it.
  consider   9 5 2 4 1 3

  now if we carefully note we find that the no. of unwanted of both halfs is always equal as they were misplaced and we are essentially going to place them in the perfect position inorder to minimize the steps.

  its only possble if first found unwanted elements in both the halfs are smartly replaced, then steps required to interchange their positions is the absolute value of their differences of their indices.

  */
  ll opcount = 0;
  fori(0, unwanted1st.size()){
    opcount += (unwanted2nd[i] - unwanted1st[i]);
  }

  cout << opcount << endl;
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

