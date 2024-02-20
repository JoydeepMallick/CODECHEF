#include<iostream>
using namespace std;
int main()
{
	int t,x,n;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		cin>>n>>x;
		if (x<n)
		{
			cout<<x<<endl;
		}
		
		else
		{
			while(x>n)//for very large numbers it may be repeatative
				x=(x-n-1);
			cout<<x<<endl;
		}
	}
	return 0;
}