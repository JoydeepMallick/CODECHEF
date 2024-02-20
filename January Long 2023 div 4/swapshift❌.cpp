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
  int n;
  cin >> n;
  int a[n+1] = {0};
  int ind ;
  fori(1, n+1){
    cin >> a[i];
    if(a[i]==1) ind = i;
  }
  //lexicographically smallest means the sorted array.1 2 3 ....
  //no impoosible case i stated, always such a array(not neccessarily completely sorted since we are limited to 2 swaps) can be constructed at most 2 swaps and infinite left shifts(rotation).
  //
  //so we will try to bring 1 to the front of the array by shifting entire array.
  //once done we will simple perform 2 swaps for index i(1 to n) when ai!=i and this array will be our lexicographically smallest possible following blob condition
  /*
    5 2 1 4 3 after shifting becomes 1 4 3 5 2
    we just need to search for indices of values 2 and 4
    in below operations.
    now swap 4 with 2,   1 2 3 5 4
    now swap 5 with 4,   1 2 3 4 5

    2nd case is the same post shifting 1 to 1.....

don’t swap 11" case always gives us an array starting with [1,2,3][1,2,3] at the very least.

So, in this case it’s pointless to consider doing anything that doesn’t at least match that.
   */
  int newa[n+1] = {0};
  mii positionof;
  //shifting 1 to index 1
  fori(1,n+1){
/* dbg((ind!=n)? ind%n : ind); */
    newa[i] = a[(ind!=n)? ind%n : ind];
    //mapping indices of each value
    positionof[newa[i]] = i;
    ind++;
  }
  //perform at most 2 swap operations
  int swapped = 0;
  ind = 1;//1 is already placed in correct position
  while(swapped < 3 && ind < n){
    //ind is less than n because we can surely tell we encountered n somewhere before and placed it at most at the time when ind was n-1  else swap limit had already exceeded and we never reach ind = n
    if(newa[ind] != ind){
      //search for index of ind
      int indisat = positionof[ind];
      //swap value of keys (newa[ind]) and (ind) in map
      swap(positionof[newa[ind]], positionof[ind]);
      //swap in actual array newa
      swap(newa[ind], newa[indisat]);
      swapped++;
    }
    ind++;//go to next element
  }
  fori(1,n+1) cout << newa[i] << " ";
  cout << endl;

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

