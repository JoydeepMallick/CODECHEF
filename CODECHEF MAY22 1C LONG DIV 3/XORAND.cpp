/*
 __________________________
|  Written by silent_Joy  |
   ---------~u~---------  

*/

#include<bits/stdc++.h>

//int can be mentioned with long or skipped as you wish

#define si short int // -2^15 to 2^15 - 1
#define usi unsigned short int // 0 to 2^16 - 1
#define ui unsigned int // 0 to 2^32 - 1
#define li long int // -2^31 to 2^31 - 1
#define ul unsigned long int // 0 to 2^32 - 1
#define ll long long // -2^63 to 2^63 - 1
#define ull unsigned long long // 0 to 2^64 - 1
#define ld long double // 12 bytes (12*8 bits)
#define us unsigned char // 0 to 2^8 - 1

using namespace std;

#define len(str) str.length();

void test(){
	//write code here
  int n,c,q,power,l,r,x;
  ui temp;
  cin >> n;
  ui arr[n];
  for(int i = 0;i < n; i++)
    cin >> arr[i]; 
  
  int dp[n+1][33];
  for(int i = 0; i <= n; i++)
    memset(dp[i], 0, sizeof(dp[0]));
 
  for(int i = 1; i <= n; i++)
  {
    temp = arr[i-1];
    for(int j = 0; j < 33; j++)
      dp[i][j] = dp[i-1][j];
    power = 32;
    if(temp != 0)
      power = (int)(log(temp)/log(2));
    dp[i][power]++;
  }
  
  cin >> q;
  while(q--)
  {
    cin >> l >> r >> x;
    power = 32;
    if(x != 0)
      power = (int)(log(x)/log(2));
    c = dp[r][power] - dp[l-1][power];
    cout << (r-l+1-c)<<"\n";
  }

}

int main(){
  //disables synchronization between C and C++ standard streams
  //prevents mixing of C and C++ code ensuring better performance
    ios_base::sync_with_stdio(false);
  
  //use only when you dont need immediate flushing(avoid in interactive problems)
    //cin.tie(false);

	int t;
	cin >> t;
	while(t--)
		test();
	return 0;
}

