#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,x,y;
	cin>>t;
	for (int i = 0; i < t; i++)
	{
		cin>>x>>y;
		if ((int)(x/2)>y)
		{
			cout<<y<<endl;
		}
		else if ((int)(x/2)<y)
		{
			cout<<(int)(x/2)<<endl;
		}
		else
		{
			cout<<y<<endl;//2 bananas for each apple
		}
	}
	return 0;
}