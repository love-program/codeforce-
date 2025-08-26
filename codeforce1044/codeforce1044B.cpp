#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;cin>>k;
    while(k--)
    {
        int n;cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        if(n%2==1){
            long long ans=a[0];
            for(int i=2;i<n;i+=2) ans+=a[i];
            cout<<ans<<endl;
        }
        else{
            long long ans=0;
            for(int i=1;i<n;i+=2) ans+=a[i];
            cout<<ans<<endl;
        }
    }
}