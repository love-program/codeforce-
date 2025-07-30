#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		int n,j,k;
		cin>>n>>j>>k;
		vector<int>a(n);
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
		}
		if(k>1){
			cout<<"Yes"<<endl;
			continue;
		}
		else
		{
		int current=a[j-1];
		sort(a.begin(),a.end());
		if(current<a[n-1])
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;
		}
			
		}
	}
}
