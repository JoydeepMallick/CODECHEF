'''
Akash goes to class everyday. His classes are held on the 9th floor so he uses a lift. One day N people get on the lift. However, since the lift can carry at most N−2 people, 2 of them need to get off.

Given an array A of the weights of the N people, Akash wonders how many ways of removing 2 people exist such that the mean of weights of the people in the lift remains constant. In other words, the mean of weights of the N−2 people remaining in the lift must be the same as the mean of weights of all the N people who were initially on the lift. Help Akash find how many such ways exist.

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first line of each test case contains an integer N - the number of people who get on the lift initially.
The second line of each test case contains N space-separated integers A1,A2,…,AN denoting the weights of the N people on the lift.
Output Format
For each test case, print a single integer denoting the number of ways of removing 2 people such that the mean reamins the same.

Constraints
1≤T≤1000
3≤N≤105
1≤Ai≤109
Sum of N over all test cases does not exceed 2⋅105
Sample Input 1 
3
4
1 3 5 7
4
1 7 7 7
6
1 1 1 1 1 1
Sample Output 1 
2
0
15
Explanation
Test case 1: The mean of weights of all N students is 1+3+5+74=164=4.

Consider removing the people with weights (1,7). The mean of weights of the N−2 people remaining in the lift is 3+52=82=4, which is same as the mean of all N people.
Consider removing the people with weights (3,5). The mean of weights of the N−2 people remaining in the lift is 1+72=82=4, which is same as the mean of all N people.
There is no other way to remove 2 people such that the mean reamins the same. Hence the answer is 2.

Test case 2: The mean of weights of all N students is 1+7+7+74=5.5. It can be seen that there is no way to remove 2 people such that the mean reamins the same. Hence the answer is 0.
'''




'''
soultion in c++


#include<bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;
int main(){
    ll t,n,i,j;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll>v(n);
        ll s1=0;
        map<ll,ll>mp;
        for(i=0; i<n; i++){
            cin>>v[i];
            s1+=v[i];
            mp[v[i]]++;
        }
        ld d1 = (s1/(n*1.0));
        ld d2 = ((d1*1.0)*((n-2)*1.0))*1.0;
        ld rem = (s1-d2)*1.0;
        ll ans=0;
        for(i=0; i<n; i++){
            ll find = (rem-v[i]);
            if(find+v[i]==rem){
                if(find == v[i] && mp[find]>0){
                    ans+=mp[find];
                    ans--;
                }else{
                    ans+=mp[find];
                }
            }
        }
        cout<<ans/2<<"\n";
    }
}
'''


for i in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    #store freq of repeated digits
    freq = {}
    for i in a:
        if i not in freq:
            freq[i] = 1
        else:
            freq[i]+=1
    
    avg = sum(a)/n
    new_sum = avg * (n-2)
    sum_to_rem = sum(a) - new_sum
    
    ans = 0
    for ele in a:
        find = int(sum_to_rem - ele) # key to find
        if find in freq.keys(): #find+ele == sum_to_rem and  
            if find==ele and freq[ele]>0:#same elements twice == sum_to_rem
                ans+=freq[find]
                ans-=1
            else:
                ans+=freq[find]
    print(ans//2)
    
            
