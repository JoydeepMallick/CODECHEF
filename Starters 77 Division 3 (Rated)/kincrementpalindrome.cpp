/*
   __________________________
   |  Written by silent_Joy  |
   ---------~u~---------  
   */
#include"bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt") //intel pentium porcessors released post 2020 support avx2, unfortunately my Pentium 2020M doesn't 
using namespace std;

/*______________________MACRO DEFINATIONS______________________*/

#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int> >
#define vvll vector<vector<long long> >

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

//loop constructs shortened using macro defination
#define fori(a, n) for (ull i = a; i < (ull)n; i++)
#define forj(a, n) for (ull j = a; j < (ull)n; j++)
#define fork(a, n) for (ull k = a; k < (ull)n; k++)

#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*_________________CONSTANTS FREQUENTLY USED__________________*/

const int mod = 1000000007;//10^9+7
const ull PI   = 3.141592653589793238462;

/*__________________ FUNCTION DEFINATIONS _____________________*/


ull lcm(ull x, ull y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS using inbuilt function __gcd(x,y)

/*__________________________ DEBUGGER _________________________*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _do() {cerr << " \n";}

template <typename T, typename... V>
void _do(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _do(v...);}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr <<"JOY_DBG active :- " <<  #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
#else
#define dbg(...)//arrays can't be debugged with this, use std::array instead
#endif

/*_________________________________WRITE YOUR CODE FOR EACH TEST CASE BELOW____________________________________*/

void printarr(int n, int arr[]){
    cout << "{ ";
    fori(0,n) cout << arr[i] << " ";
    cout << "}\n";
}

bool isequal(int a[], int b[],int n){
  fori(0,n){
    if(a[i] != b[i]) return false;
  }
  return true;
}

void test(){
  int n,k;
  cin >> n >> k;
  int a[n];
  int s = 0;
  fori(0,n){
    cin >> a[i];
    s += a[i];
  }
  /*
   * if k = 1 always possible since we can pick each element individually and make array palindrome.
   *
   * and if k = n then never possible
   *
   * assume a series a1 a2 a3 a4   where a1 and a4 are equal and k=3
   *
   * we can in one operation select a1, a2, a4 then a1 and a4 increase by one and remain same and a2 gets updated hence we are performing k = 1 operation indirectly.
   *
   *
   * WE will try to implement above property for each array hence if k = odd then we can select all palindromic pairs and the element we want to update.
   *
   * assume k = 3 and a = 3 1 2 4  
   * then if we update 2nd element, 4 2 2 5
   * now we update 1st element then 5 2 2 5
   * hence its possible if update all pair positions and the postion of element we want to change, therby the palindromic string qation changes relatively.
   *
   *
   * now again if n = odd then also its possible.
   * if a = 3 4 2 3 1  and k = 4
   *
   * then we can definitely say that updating mid will have NO EFFECT....
   * hence we will select mid and another element we want to update and rest we will select the pairs of palindromic positions.
   * i.e. if we update 5th element,   3 5 3 4 2
   * if we update last element again, 3 6 4 5 3
   * now update 4th element ,         4 6 5 6 3
   *
   *
   * now what if n is even and k is even
   *
   * it can proved that sum of elements must be even to satisfy palindrome constraint
   *
   * assume any even palindrome array   a1 a2 a3 a4  i.e. a1 and a4 equal,   a2 and a3 equal
   * then a1+a4 and a2+a3 both are even sum by any means.
   *
   * assume 3 1 4 2        and k = 2  
   *  ->    3 2 4 3
   *  ->    3 3 4 4 
   *  ->    4 4 4 4     
   *
   *
   *  again assume  3 1 4 3   and  k = 2
   *            ->  3 2 4 4 
   *            ->  4 3 4 4 
   *            ->  5 4 4 4  
   *            ...........
   *            ...........
   *
   *
   *            it can never be made palindrome. 
   */
  //if n == k then only possible if array is already palindrome
  int b[n];
  copy(a, a+n, b);  
  reverse(b,b+n);
/* printarr(n,a); */
/* printarr(n,b); */
    if(isequal(a,b,n)) yes;
    else if( k!=n && ( n&1 || k&1 || s%2==0)  ) yes;//if n or k is odd then it may be palindrome else can be converted to palindrome and if both n and k arre even then if sum of all elements is even then only its possible.
    else no;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int t = 1;//if test case is 1 only please comment out cin statement below
  cin >> t;
  auto t1 = std::chrono::high_resolution_clock::now();
  int temp = t;
  while(t--){
#ifndef ONLINE_JUDGE
    cout << "________________________ TEST CASE #" << temp-t << " ________________________" << endl;
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


