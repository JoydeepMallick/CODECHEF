/*
Consider an array AA consisting of NN positive elements. The frequency array of AA is the array BB of size NN such that Bi=Bi​= frequency of element AiAi​ in AA.

For example, if A=[4,7,4,11,2,7,7]A=[4,7,4,11,2,7,7], the frequency array B=[2,3,2,1,1,3,3]B=[2,3,2,1,1,3,3].

You have lost the array AA, but fortunately you have the array BB.
Your task is to construct the lexicographically smallest array AA such that:

    1≤Ai≤1051≤Ai​≤105;
    The frequency array of AA is equal to BB.

If no such array AA exists, print −1−1.

Note: Array XX is lexicographically smaller than array YY, if Xi<YiXi​<Yi​, where ii is the first index where XX and YY differ.
Input Format

    The first line of input will contain a single integer TT, denoting the number of test cases.
    Each test case consists of two lines of input.
        The first line of each test case contains a single integer NN — the size of the array.
        The next line contains NN space-separated integers - B1,B2,…,BNB1​,B2​,…,BN​, the frequency array.

Output Format

For each test case, output on a new line, NN space separated integers - A1,A2,…,ANA1​,A2​,…,AN​, the lexicographically smallest array AA. If no such array AA exists, print −1−1.
Constraints

    1≤T≤1051≤T≤105
    1≤N≤1051≤N≤105
    1≤Bi≤1051≤Bi​≤105
    The sum of NN over all test cases won't exceed 106106.

Sample 1:
Input
Output

5
5
2 3 3 3 2
5
1 1 1 1 1
5
5 5 5 5 5
3
1 2 4
8
1 3 2 3 2 2 2 3

1 2 2 2 1
1 2 3 4 5
1 1 1 1 1
-1
1 2 3 2 3 4 4 2

Explanation:

Test case 11: The lexicographically smallest array AA having the given frequency array BB is A=[1,2,2,2,1]A=[1,2,2,2,1]. The element A1A1​ and A5A5​ have frequency 22 while A2,A3,A2​,A3​, and A4A4​ have frequency 33.

Test case 22: The lexicographically smallest array AA having the given frequency array BB is A=[1,2,3,4,5]A=[1,2,3,4,5]. Each element in AA has frequency 11.

Test case 33: The lexicographically smallest array AA having the given frequency array BB is A=[1,1,1,1,1]A=[1,1,1,1,1]. Each element in AA has frequency 55.

Test case 44: No possible array AA exists having the given frequency array.
*/
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
    int b[n];
    mii fof;//frequency of frequency
    bool possible = false;
    fori(0, n){ 
        cin >> b[i];
        fof[b[i]]++;
        if(fof[b[i]] < b[i]) possible = false;
        else {
            possible = true;
            fof[b[i]] = fof[b[i]]%b[i];//we leave the remainder to again add up
        };
    }
    if(possible){
        //we already have count of distinct digits from 1 till n as values sum in map
        int counter = 1;
        map<int, pair<int,int>> toprint;
        fori(0,n){
            if(toprint[b[i]].second == 0) {
                toprint[b[i]].first = counter;
                //new key means new value
                counter++;
            }
            toprint[b[i]].second++;
            cout << toprint[b[i]].first << " ";
            if(toprint[b[i]].second%b[i] == 0){
                //delete this key
                toprint.erase(b[i]);
/* counter++; */
            }
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
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

