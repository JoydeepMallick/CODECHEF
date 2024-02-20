/*
You are given a string S of length N, containing lowercase Latin letters. You are also given an integer K.

You would like to create a new string S′ by following the following process:

First, partition S into exactly K non-empty subsequences S1,S2,…,SK. Note that every character of S must be present in exactly one of the Si.
Then, create S′ as the concatenation of these subsequences, i.e, S′=S1+S2+…+SK, where + denotes string concatenation.
Determine the lexicographically smallest S′ that can be created.

Input Format
The first line of input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers, N and K.
The second line of each test case contains the string S.
Output Format
For each test case, output on a new line the lexicographically smallest string S′ that can be created.

Constraints
1≤T≤1000
1≤N≤105
1≤K≤N
S contains only lowercase Latin letters.
Sum of N over all cases won't exceed 2⋅105.
Sample Input 1 
3
6 1
whizzy
14 2
aaacdecdebacde
4 3
dbca
Sample Output 1 
whizzy
aaaaccdecdebde
abcd
Explanation
Test Case 1: K=1, so our only option is to set S′=S1=whizzy.

Test Case 2: Partition S=aaacdecdebacde into S1=aaaac and S2=cdecdebde, to form S′=aaaaccdecdebde.

Test Case 3: Partition S=dbca into S1=a, S2=bc, and S3=d to form S′=abcd.

In both test cases 2 and 3, it can be shown that no other partition gives a lexicographically smaller S′.
*/

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl cout<<'\n'
#define vll vector<ll>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) (ll)(v.size())
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mxheap priority_queue<ll>
#define mnheap priority_queue<ll,vector<ll>,greater<ll>>
#define FIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
void solve(){
    ll n,k,i=0;
    string s;
    cin>>n>>k>>s;
    if(k==1){cout<<s;nl;return;}
    string t=s;sort(all(t));
    if(k>25){cout<<t;nl;return;}
    while(k-->2)for(auto&x:s)if(x==t[i])cout<<x,x='{',i++;
    vector<bool>v(n);
    char c='z',x='{';
    for(i=n-1;i>=0;i--)if(s[i]<=c)c=s[i],v[i]=1;
    for(i=0;i<n;i++){
        if(s[i]=='{' || v[i])continue;
        if(x=='{')x=s[i];
        else if(x!=s[i])break;
    }if(s[i]<x)x--;
    for(i=0;i<n;i++)if(v[i] && s[i]<=x)cout<<s[i],s[i]='{';
    for(auto&x:s)if(x!='{')cout<<x;nl;
}
int main(){FIO;ll t;cin>>t;while(t--)solve();}