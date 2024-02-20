#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,x,y;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>a>>b>>x>>y;
		if (x*y>=a*b)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}

	return 0;
}