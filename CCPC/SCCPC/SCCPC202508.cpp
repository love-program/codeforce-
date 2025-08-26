//cin太慢了，需要换成scanf
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;cin>>k;
    while(k--)
    {
        int a,b,x,y;
        //cin>>a>>b>>x>>y;
        scanf("%d %d %d %d",&a,&b,&x,&y);
        int m=abs(x-a);int n=abs(y-b);
        int need_x,need_y;
        if(m==0)
        {
            need_x=2;
        }
        else
        {
            need_x=(m+1)/2;
        }
        if(n==0)
        {
            need_y=2;
        }
        else
        {
            need_y=(n+1)/2;
        }
        if(m==0&&n==0)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<max(need_x,need_y)<<endl;
    }
}