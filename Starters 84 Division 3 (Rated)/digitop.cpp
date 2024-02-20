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
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    read(a,n);
    read(b,n);

    /*
        22   13   12  89    a  
        28   98   21  31    b

        freq for a        freq of b  
        1 - 2             1 - 2
        2 - 3             2 - 2 
        3 - 1             3 - 1 
        8 - 1             8 - 2 
        9 - 1             9 - 1 

        for elements with same freq like 1 for both a and b it can be swapped hence remove it  .
        now 2 in b is 2 but a has 3 2s some remove 2 from 3 and we are left with one 2 in a 

        freq for a        freq of b  
        1 - 0             1 - 2-2 = 0
        2 - 3-2 = 1       2 - 2-2 = 0    <---   need to replace 2 from a 
        3 - 0             3 - 1-1 = 0 
        8 - 1-2 = (-1)    8 - 2-2 = 0    <---   need to add 8 to a 
        9 - 0             9 - 1-1 = 0 

Steps :-
1. take freq of all elements of array
2. subtract freq of second array from first array 
3. in a, if freq is +ve means surplus, neeed to be modified 
4. in a, if freq is -ve then deficiency, need to be modified

Note :- if sizes of 2 numbers are not equal they cant be made equal by any number of moves

MY implementation does not work!!! below is accepted code.


*/
    bool equallength = true;
    mii freq_combo;
    //default value of map int value  is 0
    fori(0,n){
        for(auto c : to_string(a[i])) freq_combo[c-'0']++;
        for(auto c : to_string(b[i])) freq_combo[c-'0']--;
        if(to_string(a[i]).size() != to_string(b[i]).size()) {
            equallength = false;
            break;
        }
    }

    dbg(freq_combo);
    if(!equallength) no;
    else{
        int cost = 0;
        for(auto it : freq_combo){
            cost += abs(it.second);
        }
        if(cost/2 <= k) yes;
        else no;
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

/*
 #include<bits/stdc++.h>
#include <iostream>
using namespace std;
#define int long long

signed main() {
 // your code goes here
 int T;
 cin>>T;
 while(T--){
     int n,k;
     cin>>n>>k;
     
     vector<string> a,b;
     
     for(int i=0;i<n;i++){
         string x;
         cin>>x;
         
         a.push_back(x);
     }
     for(int i=0;i<n;i++){
         string x;
         cin>>x;
         
         b.push_back(x);
     }
     
     int fi=0;
     for(int i=0;i<n;i++){
         if(a[i].size()!=b[i].size()){
             fi=1;
             break;
         }
     }
     
     if(fi==1){
         cout<<"no"<<endl;
     }
     else
     {
        vector<int> v(10,0);
        vector<int> u(10,0);
         for(auto val:a){
             for(auto pp:val){
                 int x = pp-'0';
                 v[x]++;
             }
         }
         
          for(auto val:b){
             for(auto pp:val){
                  int x = pp-'0';
                 u[x]++;
             }
         }
int count=0;
for(int i=0;i<10;i++){
    count+=abs(v[i]-u[i]);
}
if(count/2<=k){
    cout<<"yes"<<endl;
}

else{
    cout<<"no"<<endl;
}        
     }
     
 }
 return 0;
}
   */
