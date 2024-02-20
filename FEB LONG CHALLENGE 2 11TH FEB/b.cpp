#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,x;
	string s;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int d=0,c=0,n=0;
		cin>>x;
		cin>>s;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i]=='D')
				d+=1;
			else if (s[i]=='C')
				c+=1;
			else 
				n+=1;
		}
		c=2*c+1*d;
		n=n*2+1*d;
		if (c>n)
			cout<<60*x<<endl;
		else if (c<n)
			cout<<40*x<<endl;
		else if (c==n)
			cout<<55*x<<endl;
	}

	return 0;
}