//小小贪心，拿下拿下
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n,s;
        cin>>n>>s;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        vector<int> b(2);
        b[0]=b[1]=s;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=b[0])
            {
                b[0]=ceil((double)(a[i]+b[0])/2);
            }
            else
            {
                b[1]=b[1]*2+1;
            }
        }
        cout<<b[0]<<endl;
    }
}