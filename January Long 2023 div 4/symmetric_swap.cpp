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
  int a[n],b[n];
  fori(0,n){
    cin >> a[i];
  }
  fori(0,n){
    cin >> b[i];
  }
  /*
   first we update ai and bi and ensure that ai <= bi

   then create a new array c with pairs a[i],b[i] and SORt it(will help in further calculation).
   HENCE  initially c[n-1][0] - a[0][0] will be the answer.


   ______________________doubt_________________________
   Now we will always want to minimize ith element of a.
   this is not possilbe(i.e. if some aj and bj same) always but a way to do that:-

    swap aj and bj  for j < i hence we are trying to make all a0 to a(i-1) grater than ai. 

    But if we already have MADE a smallest possible, swapping with b[i] can increment the value of a[i] rather than reducing it and hence we get a different combinaiton..... 
_____________________________________________________________
    this is done basically to ensure all possible combinations of array a in a single iteration since we are limited to swap same indices only.

    Now we simply find the difference between max and min of current updated a after each such swap...

    In practical searching in an array for n iterations would take n*n time.

    But we reduce it O(1) using multiset storing all elements of a after it values have been made small by swapping with b. we can rest assured of the order of elements since we have already stored pairs of ai and bi previously which will help us to find ai corresponding bi.

    Now each swap can be done in less time and difference is simply the diff of first and last element of updated mutiset.


    NOw to calculte the final answer we just need the minimum of such differences we calculate for each i.

   */
    //make a as small as possible
  fori(0,n){
    if(a[i] > b[i]) swap(a[i], b[i]);
  }
  //store a in multiset for future use
  multiset<int> sorteda;
  fori(0,n){
    sorteda.emplace(a[i]);
  }
  int ans = *sorteda.rbegin() - *sorteda.begin();
  multiset<pii> c;// we use multiset to avoid sorting and faster searching
  fori(0,n){
    c.emplace(make_pair(a[i],b[i]));
  }

  //now sorteda and c both are  in sorted fashion
  //in each iteration we 
  auto it = c.begin();
  fori(0,n){
    sorteda.erase(sorteda.find((*it).first));//remove sorteda[i]
    sorteda.emplace((*it).second);//place c[i].second ie b correspodning element 
    ans = min(ans, *sorteda.rbegin() - *sorteda.begin());
    //update c
    it++;
  }

  cout << ans << endl;

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

