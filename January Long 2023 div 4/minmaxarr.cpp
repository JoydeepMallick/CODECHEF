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
    ll a[n];
    fori(0, n){
        cin >> a[i];
    }
    /*
COncept :-

to reduce two adjacent values to a minimum we must always try to rqualize them as much as possible.

1 5 7 6 
we should start from index 1 till n-1
now 5-1/2 = 2 hence x = 2

3 3 7 6

NOW we need to distribute excess of 7 to the elements before it. this has to done in TWO steps but in simple terms, we can say (7-3)/2 = 2 which needs to be first given to adjacent 3

3 5 5 6
now again balance 3 and 5 as x = 1
hence we essentially gave 1 to both 3s

4 4 5 6

now comes 6 difference is 1 can half it but we can send it aloong previous for further reduction if possible until its hits index 0 where no more operations are possible hence x= 1

4 4 6 5
again difference is 2 so distribution occurs by 1
4 5 5 5
again difference is 1 so send it

5 4 5 5 

NO FURther operations to reduce the array further, hence max = 5




now 2nd case  5 15 19 
diff is 10 so x = 5
10 10 19
diff is 9  so   9/2 = 4 ,   10 14 15
diff is 4 so x = 2    12 12 15
again diff = 3 so let x = 2   12 14 13
again diff = 2 so x = 1 ,13 13 13 hence max = 13




last case   10 3 5 7

since first element is 10 it can never be reduced, hence answer is always 10.


Apporach :-
___________

we initially set our ans to a[0] first element

now we sum elements of arr one by one i.e. sm = a[0] ans  sm+=a[i]

now our ans will max(ans, currentsum/(no of elements considered till now in sum))

i.e. max(ans. sum/ (i+1))


now in case the difference of adjacent elements is a odd number we take the ceiling of division since we always will have a uneqaul distribution.

this can be solved by ceil function, but we can also perform the following
floor((sum+i)/(i+1))
here we are adding a 1 to all i elements before ith index

     */
    ll result = a[0], sm = a[0];
    fori(1,n){//start from index1
      sm += a[i];
      result = max(result, (ll)ceil(sm/(ld)(i+1)));

    }
    cout << result << endl;
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

