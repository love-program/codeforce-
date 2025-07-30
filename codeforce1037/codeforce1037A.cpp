#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; 
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string a;
        int ans=9;
        cin>>a;
        for(int j=0;j<a.length();j++)
        {
            if(ans>(a[j]-'0'))
            {
                ans=(a[j]-'0');
                if(ans==0)
                break;
            }
        }
        cout<<ans<<endl;
    }
}
