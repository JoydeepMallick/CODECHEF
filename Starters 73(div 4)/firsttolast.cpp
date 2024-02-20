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
    int n,m,k;
    cin >> n >> m >> k;
    if(k){
        int a[k];
        fori(0,k) cin >> a[i];
    }
    /*
     * DP required...
     *
          normal moves         special cell moves
                |                    \|/
            ---   ---             ---   ---
                |                    /|\

        A simple BFS would do the job to find the minimum path in graph but it would have a time complexity of n*m which is undesirable.

        but number of cells is 2*10^5 which is less hence iterating over each cell is acceptable i.e. TC of k or klogk is acceptable.

        First case
        ----------

        when no special cells, minimum no moves is always a constant answer
        The no of cells traversed is equal to number of rows + no. columns -1(beacuse one cell is counted twice while movement)
        Hence the number of moves made is n+m-1 -1 = n+m-2


        2nd CASE
        --------

        In case of any special cell only three moves will be useful
        i.e. right, down, and right down diagonal

        In case of right down diagonal we actually cover the 2 moves in a move which reduces cost.

        but a special cells special feature can only be used only when 
it defintely has a cell below and to its right side.

To reduce cost we never want to visit a row twice with a special cell hence upward right diagonal movement is not accepted.

Hence all lower and right corner cells which are special are rednered normal cells to use.

                        |
                        |
              __________|
    

And once a special cells special move is used, we can ensure that we are never visiting that row again where the special cell was.

Basic approach:-

store all special cells only if they ain't have the same column as m or row as n hence avoiding useless special cells
*** moreover each row and column can have only one usable special cell, since once its used, we never are going to return to that ROW or COLUN.
Hence coordinates of special cells must be distinct and increasing i.e if a special cell is in (2,3) then another usable special cell after it must be something(3+++,4++++) 

our motive is to use as many special cells as possible to move diagonally downwards, hence if a case is such that special cells in  n=7 , m = 10 are (2,9), (3,4),(5,7),(6,8),(7,10) then avoiding 2,9 is  btter ......


step1.  so at our current index we always go on checking if current row+1 is a special cell or not , if not move right else move down to special cell.
i.e. current index is updated to row,column+1

step2.  if we are in a special cell we move diagonally right downwards
and update current index as row+1, column+1

step3.  

     */
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

