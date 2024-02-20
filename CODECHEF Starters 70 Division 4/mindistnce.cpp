/*
Chef has a binary string SS of size NN. Chef can perform the following operation on the string:

    Select any substring of size 33 and reverse it.

Find the minimum distance between any two 11s Chef can achieve, by applying the above operation any (possibly zero) number of times.

Note:

    The distance between two characters SiSi​ and SjSj​ is defined as abs(i−j)abs(i−j).
    It is guaranteed that the string contains at least two occurrences of 11.
    A substring is obtained by deleting some (possibly zero) elements from the beginning and some (possibly zero) elements from the end of the string.

Input Format

    The first line of input will contain a single integer TT, denoting the number of test cases.
    Each test case consists of multiple lines of input.
        The first line of each test case contains an integer NN — the number of characters in the string.
        The next line contains a binary string of length NN.

Output Format

For each test case, output on a new line, the minimum distance between any two 11s Chef can achieve, by applying the above operation any (possibly zero) number of times.
Constraints

    1≤T≤10001≤T≤1000
    2≤N≤1052≤N≤105
    SiSi​ contains 00 and 11 only.
    It is guaranteed that SS contains at least two occurrences of 11.
    The sum of NN over all test cases won't exceed 2⋅1052⋅105.

Sample 1:
Input
Output

3
2
11
3
101
7
0100101

1
2
1

Explanation:

Test case 11: There are only two 11s in the string. The distance between the 11s is 2−1=12−1=1.

Test case 22: The distance between the given 11s is 3−1=23−1=2. It can be shown that we cannot achieve a distance smaller than 22 by applying any number of operations.

Test case 33: Chef can perform the following operation:

    Select the substring S[2,4]=100S[2,4]=100 and reverse it. Thus, the string becomes S=0001101S=0001101. The minimum distance between the 11s in the string is 5−4=15−4=1.

It can be shown that we cannot achieve a distance smaller than 11 by applying any number of operations.	
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
    string x;
    cin >> x;//substring of size 3 can be reversed
    int  diff = -1;
    //minimum difference for edge case which  is 11
    /*
    answer will always be either 1 or TWO
    reason :-  asume ....100001.....
     here after reversing we end up with ....000011....
     
     asume 1000001
     here we always endup with 0000101
    
    hence if even no of 0s(diff between idices of 1 is odd) found between two 1 answer is 1 else 2
    now in case both cases wxist we need to find the minimu tha t is 1 hence an even count is preferred
    */
    fori(0,n){
        if(x[i] == '1'){
            if(diff == -1) diff = i;
            else{
                //2nd 1 encontered.
                if((i - diff)%2){
                    diff = 1;
                    break;
                }
                else diff = i;//now again store i for next diff
            }
        } 
    }
    if(diff == 1) cout << 1 << endl;
    else cout << 2 << endl;
    
    
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

