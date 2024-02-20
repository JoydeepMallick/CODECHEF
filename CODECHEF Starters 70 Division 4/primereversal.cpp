/*
ou are given two binary strings AA and BB, each of length NN. You can perform the following operation on string AA any number of times:

    Select a prime number XX.
    Choose any substring of string AA having length XX and reverse the substring.

Determine whether you can make the string AA equal to BB using any (possibly zero) number of operations.

A substring is obtained by deleting some (possibly zero) elements from the beginning and some (possibly zero) elements from the end of the string.
Input Format

    The first line of input will contain a single integer TT, denoting the number of test cases.
    Each test case consists of multiple lines of input.
        The first line of each test case contains an integer NN — the length of the strings AA and BB.
        The second line contains the binary string AA.
        The third line contains the binary string BB.

Output Format

For each test case, output on a new line, YES, if you can make the string AA equal to BB using any number of operations and NO otherwise.

You can print each character in uppercase or lowercase. For example, YES, yes, Yes, and yES are all identical.
Constraints

    1≤T≤1001≤T≤100
    1≤N≤1051≤N≤105
    AiAi​ and BiBi​ contain 00 and 11 only.
    The sum of NN over all test cases won't exceed 105105.

Sample 1:
Input
Output

4
2
00
00
4
1001
0111
5
11000
10010
5
11000
11010

YES
NO
YES
NO

Explanation:

Test case 11: Both the strings are equal. Thus, we do not need any operations.

Test case 22: It can be shown that we cannot make the string AA equal to BB using any number of operations.

Test case 33: Choose X=3X=3 and reverse the substring A[2,4]=100A[2,4]=100. Thus, the string AA becomes 1001010010 which is equal to BB.

Test case 44: It can be shown that we cannot make the string AA equal to BB using any number of operations.
*/


/*   __________________________
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
bool isPowerOfTwo(T x){    
    return (x != 0) && ((x & (x - 1)) == 0);
}

template <typename T_all>//string,float,int,.... all types
bool isPalindrome(T_all s){
    string new_s;
    new_s = s;
    int n = len(new_s);
    fori(0,n/2){
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
unsigned int countSetBits(unsigned int n){
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

void test(){
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    //Choose any substring of string AA having length XX and reverse the substring.
    //this condition is just to make us understand than if we want to perform composite reverse we need to perform prime revierse multiple times since composite = product of primes...
    int ca0 = 0, cb0 = 0;
    fori(0,n){
        if(a[i] == '1') ca0++;
        if(b[i] == '1') cb0++;
    }
    if(ca0 == cb0) yes;
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

