#include<bits/stdc++.h>
using namespace std;
int main()
{

    int ans=1;
    int k;cin>>k;
    while(k--)
    {
        ans=1;
        int n;cin>>n;
        vector<int> span(n);
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {  
            span[i]=a[i]-b[i];
        }
        sort(span.begin(),span.end());
        reverse(span.begin(),span.end());
        for(int i=0;i<n;i++)
        {
            if(span[i]>0)
            {
                ans+=span[i];
            }
            else{
                break;
            }
        }
        cout<<ans<<endl;
    }
}