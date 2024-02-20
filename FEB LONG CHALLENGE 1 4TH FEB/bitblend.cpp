#include<bits/stdc++.h>
using namespace std;

void print_output(vector<pair<int,int>> ops){
	cout<<ops.size() << "\n";
	// 1 based indexing
	for (auto [x,y] : ops)
		cout << x+1 << " " << y+1 << "\n";
}

void test_case(){
	int n;
	cin >> n;
	int a[n];
	bool oddExists = false, odd = false, even = false;
	for (int i = 0; i < n; i++){
			cin >> a[i];
			if (a[i]%2){
				oddExists = true;
				if (i%2) odd=true; // 1 meaning true meaning odd
				else even=true;
			}
	}

	if(!oddExists) //at least one odd is required
		cout << "-1\n";
	else{
		//valid array will be alternating odd and even
		vector <pair<int,int>> ops1, ops2;//if ops1 is odd element, then ops2 is Xor converting even element
		//odd at odd position
		if (odd){
			int oddPos = -1;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 2 and (i&1)) // element odd and position also odd
					oddPos = i;
			}
			for (int i = 0; i < n; i++)
			{
				if (!(i&1) and a[i] % 2) //position even and element odd
					ops1.push_back({i,oddPos});
				else if ((i&1) and a[i] % 2 == 0)// postion odd and element even
					ops1.push_back({i,oddPos});
			}
		}

		//odd at even position
		if (even){
			int evenPos = -1;
			for (int i = 0; i < n; i++)
			{
				if (a[i] % 2 and !(i&1)) // element odd and position even(not odd)
					evenPos = i;
			}
			for (int i = 0; i < n; i++)
			{
				if (!(i&1) and a[i] % 2 == 0) //position even and element even
					ops2.push_back({i,evenPos});
				else if ((i&1) and a[i] % 2) // postion odd and element odd
					ops2.push_back({i,evenPos});
			}
		}


		int ans1 = ops1.size(), ans2 = ops2.size();
		if (odd and even){ 
			if(ans1 < ans2) print_output(ops1);
			else print_output(ops2);
		}
		else if (odd) print_output(ops1);
		else print_output(ops2);

	}

}

int main(){
	 int t;
	 cin >> t;
	 while(t--){
	 	test_case(); 
	 }
}
