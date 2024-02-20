/*

Initially, there is a magical stone of mass 2N lying at the origin of the number line. For the next N seconds, the following event happens:

Let us define the decomposition of a magical stone as follows: If there is a magical stone of mass M>1 lying at coordinate X, then it decomposes into two magical stones, each of mass M2 lying at the coordinates X−1 and X+1 respectively. The original stone of mass M gets destroyed in the process.
Each second, all the magical stones undergo decomposition simultaneously.
Note that there can be more than one stone at any coordinate X.

Given a range [L,R], find out the number of stones present at each of the coordinates in the range [L,R]. As the number of stones can be very large, output them modulo (109+7).

Input Format
The first line contains a single integer T - the number of test cases. Then the test cases follow.
The first and only line of each test case contains three integers N, L and R, as described in the problem statement.
Output Format
For each testcase, output in a single line a total of (R−L+1) space-separated integers. The ith integer will denote the number of stones present at X=(L+i−1) coordinate. As the number of stones can be very large, output them modulo (109+7).

Constraints
1≤T≤100
1≤N≤106
−N≤L≤R≤N
Sum of (R−L+1) over all the test cases doesn't exceed 105.
Sample Input 1 
3
2 -2 2
2 0 2
150000 48 48
Sample Output 1 
1 0 2 0 1
2 0 1
122830846
Explanation
Test case 1: Let us look at the number of stones for x=−2 to x=2 as the time progresses:

t=0: {0,0,1,0,0}
t=1: {0,1,0,1,0}
t=2: {1,0,2,0,1}
We have to output the number of stones at x=−2 to x=2, which is {1,0,2,0,1}.

Test case 2: Similar to first test case, We have to output the number of stones at x=0 to x=2, which is {2,0,1}.

  


*/



/*
#include<bits/stdc++.h>
using namespace std;

//nth row of pascal tiangle using dp
vector<long long int> solve(long long int n)//,long long int x,long long int y) 
{
    vector<long long int> res(n + 1, 0);
    res[0] = 1;
    for (long long int i = 0; i <= n; ++ i) {
        for (long long int j = i; j > 0; -- j) {
            res[j] += res[j - 1]%(int)(pow(10,9)+7);
        }
    }
    return res;//slicing(res,x,y);
}

void test()
{
    long long int n,l,r;
    cin >> n >> l >> r;
    vector<long long int> nth_pascal = solve(n);//,l,r);
    
    int si = l+n,ei = r+n;
    
    // for(long long int i = 0; i < r-l+1;i++)
    // {
    //     if(i!=r-l)
    //         cout << nth_pascal[i] << " 0 ";
    //     else
    //         cout << nth_pascal[i];
    // }
    
    //below code ok but sigtstp
    
    // while(si<=ei)
    // {
    //     if(n%2==1 && si%2==0) //odd row even indexing
    //         cout << 0 <<" ";
    //     else if(n%2==0 && si%2==1) //even row odd indexing
    //         cout << 0 <<" ";
    //     else
    //     {
    //         cout << nth_pascal[(int)(si/2)]<<" ";
    //     }
    //     si++;
    // }
    cout << endl;
}



int main()
{
    long long int t;
    cin >> t;
    while(t--)
        test();
    return 0;
}

*/

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

//vector macro
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vvi vector<vector<int> >
#define vvll vector<vector<long, long> >
#define vvcc vector<vector<char, char> >

//map macro
#define mii map<int, int>
#define mis map<int, string>
#define mss map<string, string>
#define msi map<string, int>
#define mci map<char, int>
#define mcc map<char, char>

//pair macro
#define pii pair<int, int>
#define pis pair<int, string>
#define pss pair<string, string>

using namespace std;

//some useful functions as macro
#define len(str) str.length();
#define all(a) a.begin(), a.end()
#define allrev(a) a.rbegin(), a.rend()
#define cielDiv(n, k) (n) / (k) + ((n) % (k) > 0) // always upper value considered

//loop constructs shortened using macro defination
#define fori(a, n) for (int i = a; i < n; i++)
#define forj(a, n) for (int j = a; j < n; j++)
#define fork(a, n) for (int k = a; k < n; k++)


const int m = 1000000007;

int binExp(int a, int b){
    int ans = 1;
    while(b){
        if (b&1){
            ans = (ans * 1LL * a) % m;
        }
        a = (a*1LL*a)%m;
        b >>= 1;
    }
    return ans;
}

void test(fact){
	//write code here
	int n, l , r; 
	cin >> n >> l >> r;

    fori(l, r+1){
        if (((n&1) ^ (i&1)) == 1) {
            cout << "0 ";
            continue;
        }

        int I = n - abs(i);
        I /= 2;

        int ans = fact[n];
        int denominator = (fact[n - I] * 1LL * fact[I]) % m;
        ans = (ans * 1LL *binExp(denominator, m-2))%m;
        cout << ans << ' ';
    }
    cout << '\n';
}

int main(){
  //disables synchronization between C and C++ standard streams
  //prevents mixing of C and C++ code ensuring better performance
  ios_base::sync_with_stdio(false);
  
  //use only when you dont need immediate flushing(avoid in interactive problems)
  cin.tie(NULL);
	
	int fact[1000000];
    fact[0] = 1;
    fori(1, 1000000){
        fact[i] = (fact[i-1] * 1LL * i) % m;
    }

	int t;
	cin >> t;
	while(t--)
		test(fact);
	return 0;
}
