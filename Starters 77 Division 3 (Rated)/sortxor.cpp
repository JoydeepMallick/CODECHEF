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

void test(){
  int n;
  cin >> n;
/* array<int, n> a{}; */
  int a[n+1];
  fori(1,n+1){
    cin >> a[i];
  }
/*
 * assume a pair [5, 2]  
 *  1. [5^2,2] = [7, 2]
 *  2. [7^2, 5] = [7, 5]
 *  3. [7^5, 5] = [2,5]
 *
 *  hence by 3 operations we can simply swap two elements
 *
 *  but out problem say to perform it at most 3*n/2 operations
 *
 *
 *  assume [7, 5, 2, 1, 2]   when sorted   [ 1, 2, 2, 5, 7 ]
 * indices  1  2  3  4  5   
 *
 * comparing sorted and unsorted part we can find 3 operations 
 *
 * 7 needs to go in place of 2  
 * 5 needs to go in place of 1 
 * 1 needs to go in place of 7  
 * these operations are enough to make the array sorted.
 *
 * if we notice in terms of indices we find a cycle
 *
 * i.e. 1->5->2->4  --> 1  
 * ie. indices [1, 5, 2, 4]
 *  elements   [7, 2, 5, 1]
 *
 *  now this concept of cycle and xor sum will help us minimize the number of operations in the given array.
 *
 *  required operations 
 *  1.  [7^2^5^1,  2,  5,  1]
 *  2.  [   -  , -^2^5^1,  5,  1] --> upon simplifying index 2 in this we can simply A^A = 0 and A^0 = A  concept.
 *  i.e. [  -    , 7 ,  5,  1]  i.e. we have sorted one index according to given array.
 *  3.  [ -   , 7 , -^7^5^1, 1 ]  -->   [  -  , 7, 2 ,1 ]
 *  4.  [ -   , 7,  2 ,  -^7^2^1 ]  -->  [ -  , 7, 2 , 5 ]
 *
 *  hence except for the first element all other elements have been sorted to correct postion. to get the frist element also correct we simply xor it with the rest other element in cycle
 *  5.  [ -^7^2^5,  7 ,  2 , 5 ]  -->  [1,7,2,5] 
 *
 *
 *
 *  HENCE STEPS TO SOLVE :-
 *
 *  1.  find cycles according to the sorted array
 *  2.  pick each index and assign xor of all values to picked index
 *  3.  at last, pick the 1st index again and assign the XOR
 *  4.  now all elements of the cycles will be placed  at corresponding postions 
 */

  int sorteda[n+1];
  copy(a+1,a+n+1, sorteda+1);
  sort(sorteda+1, sorteda+n+1);

  //map to store elements and their indices of original array
  map<int, vector<int>> elementindices;
  fori(1,n+1){
    elementindices[a[i]].push_back(i);
  }
    vector<bool> vis(n+1);
    //storing answers
    vector<pair<int, vector<int>>> ans;

    fori(1,n+1){
        if(elementindices[sorteda[i]].empty()) continue;
        vector<int> cycle;
        int ind = i;
        while(!vis[ind]){
            vis[ind]  = true;
            cycle.push_back(ind);

            int lastele = elementindices[sorteda[ind]].back();
            //pop the last element
            elementindices[sorteda[ind]].pop_back();
            ind = lastele;
        }
        if(cycle.size() <= 1) continue;

        for(int ele : cycle){
            ans.push_back({ele, cycle});
        }
        ans.push_back({cycle[0], cycle});
    }

    cout << ans.size() << endl;
    for(auto it : ans){
        int ind = it.first;
        vector<int > p = it.second;
        cout << ind << " " << p.size() << endl;
        for(int a : p) cout << a << " ";
        cout << endl;
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


