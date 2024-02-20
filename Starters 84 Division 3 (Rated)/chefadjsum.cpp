/*
   __________________________
   |  Written by silent_Joy  |
   ---------~u~---------  
   */
#include"bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
/* #pragma GCC target("bmi,bmi2,lzcnt,popcnt") */
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
#define vpii vector<pair<int,int>>
//map macro
#define mii map<int, int>
#define mis map<int, string>
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
#define mp make_pair
#define pb push_back
#define eb emplace_back

//loop constructs shortened using macro defination
#define fori(a, n) for (ull i = a; i < (ull)n; i++)
#define forj(a, n) for (ull j = a; j < (ull)n; j++)
#define fork(a, n) for (ull k = a; k < (ull)n; k++)
//some alternatives but I lousily prefer the above, trying to shift...
#define ffor(i,a,b) for(int i=(a); i < (b); i++)
#define rfor(i,a,b) for(int i=(a); i > (b); i--)
#define yes cout<<"YES\n"
#define no cout<<"NO\n"

/*_________________CONSTANTS FREQUENTLY USED__________________*/
const int mod=1e9+7;//10^9+7
const int inf=1e9;
const ll INF=1e18;
const ld PI = 3.141592653589793238462;

/*__________________ FUNCTION DEFINATIONS _____________________*/


ull lcm(ull x, ull y){return x*y/std::__gcd(x,y);} // LCM OF TWO NUMBERS using inbuilt function __gcd(x,y)

// This is a template function that takes in two arguments, a and b, and updates the value of a to be the minimum of the two. It returns true if a was updated, and false otherwise.
template<class T> bool umin(T& a, T b){return a>b?(a=b,1):0;}
// This is similar to umin, but updates a to be the maximum of the two values.
template<class T> bool umax(T& a, T b){return a<b?(a=b,1):0;}

template<typename T>
void read(vector<T>& v) {for (auto& x : v) {cin >> x;}}

template<typename T>
void read(T arr[], int n) { for (int i = 0; i < n; i++) { cin >> arr[i];}}

template<typename T>
void print(const vector<T>& v) {for (auto x : v) { cout << x << " ";} cout << endl;}

template<typename T>
void print(const T arr[], int n) {for (int i = 0; i < n; i++) {cout << arr[i] << " ";}cout << endl;}

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

void test(){
    int n;
    cin >> n;
    int a[n];
    read(a,n);
    
/* int b[n]; */
/* copy(a, a+n, b); */
/* sort(b, b+n); */
    //print(b,n);
    //

    /*
        3 3 5 5  max  10  YES  if 5 3 3 5  or  5 3 5 3

        3 3 5     NO   but   3 5 5  yes as  3 5 3  
        3 3 3 3 3 5  NO  
        3 3 5 5 5   yes 5 3 5 3 5
        3 3 3 5 5  YES  3 5 3 5 3  
        3 3 3 5 5 5    YES
        3 3 3 3 3 5 5  YES
        3 3 5 5 5 5 5  NO 

        i.e. placement at alternate such that the max 2 element never go side  by side 

    so if 2 distinct elements then if(count(max)) == 1  or if(count(max) - count(2nd mx) > 1) then no always.

        1 3 5  always YES  
        1 3 3 5 5   always yes  
        1 3 3 5 always yes 
        1 3 5 5 always yes 
        1 3 3 5 5 5 5 5    never possible             5 1 5 3 5 3 5 5 
        1 3 3 3 3 3 5 5    yes                      5 1 5 3 3 3 3 3
        1 3 3 3 3 3 3 5                             5 1 3 3 3 3 3 3
        
        if count(max) > count(all other element) no 
        else yes;

        5 5 .... 5 aways no

        if all same always no  
        


error :-

1 3 5 5 5 5 5   no expected  
     */
    mii freq;
    fori(0, n){
        freq[a[i]]++;
    }

    dbg(freq);

    if(freq.size() == 1 || n <=2 ) no;
    else if(freq.size() == 2){//2 distinct element 
        if(freq.rbegin()->second == 1  || (freq.rbegin()->second - freq.begin()->second) > 1) no;// if max element has higher freq and more diffrence also 
        else yes;
    }
    else{
        //for distinct element >= 3
        int fmax = freq.rbegin()->second;
        int fallothers  = 0;
        auto it = freq.begin();//skip thelaast
        int till = freq.size() - 1;
        while(till--){
            fallothers += it->second;
            it++;
        }
        dbg(fmax, fallothers);
        if(fmax - fallothers > 1) no;
        else yes;
        
    }
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


