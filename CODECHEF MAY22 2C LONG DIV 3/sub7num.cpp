/*
Kulyash has given you an array A of size N.

He defines the subsequence-number of a non-empty subsequence S of array A as the number formed by the concatenation of all the elements of the subsequence S.

Find the count of non-empty subsequences of A having their subsequence-numbers divisible by 7. Since the answer can be huge, output it modulo 109+7.

For example: Consider A=[1,2,3,4,5,6,7,8,9,10]. A subsequence S of A is [2,5,7,10]. The subsequence-number of this subsequence is 25710.

Input Format
The first line will contain T, the number of test cases. Then the test cases follow.
The first line of each test case contains one integer N, the size of the array.
The second line of each test case contains N space-separated integers A1,A2,…,AN — the elements of the array A.
Output Format
For each test case, output in a single line the number of subsequences with subsequence-number divisible by 7 modulo 1000000007.

Constraints
1≤T≤1000
1≤N≤3⋅105
1≤Ai≤3⋅105
Sum of N over all test cases does not exceed 3⋅105
Sample Input 1 
3
2
1 2
4
1 2 3 4
2
7 7
Sample Output 1 
0
1
3
Explanation
Test case 1: Only 3 subsequences are possible for the given array. These are [1], [1,2], and [2]. The subsequence-numbers are 1, 12, and 2 respectively. None of the subsequence-numbers are divisible by 7, so the answer is 0.

Test case 2: [1,4] is the only subsequence having its subsequence-number 14 which is divisible by 7. So, the answer is 1.

Test case 3: All the non-empty subsequences [7], [7], and [7,7] have their subsequence-numbers 7,7, and 77 divisible by 7. So, the answer is 3
*/


#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
	ll t,n;
	const ll mod = 1000000007;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll arr[n];
		for(ll i = 0; i< n; i++)
			cin >> arr[i];
		vector<vector<int>> dp(n+1, vector<int>(7));
		dp[0][0] = 1;
		for(ll i = 0; i<n; i++)
		{
			ll l = (ll)to_string(arr[i]).size();
			ll p = 1;
			while(l--)
				p*=10;
			for(ll j = 0; j<7; j++)
			{
				int use = (j * p + arr[i]) % 7;
				dp[i + 1][j] = (dp[i+1][j] + dp[i][j]) % mod;
				dp[i + 1][use] = (dp[i+1][use] + dp[i][j]) % mod;
			}	
		}
		cout << (dp[n][0] - 1 + mod) % mod << '\n';
	}
	return 0;
}