//爆栈了，要先学习前缀和再做
#include<bits/stdc++.h>
using namespace std;
const int N =1e6;
long long l,r=0; 
int main()
{
    int k;
    long long cur=0;
    cin>>k;
    vector<int> x(2e6+10,0);
    
    while(k--)
    {
        int m;
        char n;
        cin>>m>>n;
        if(n=='R')
        {
            int temp=0;
            while(temp<m)
            {
                x[N+cur+temp]=(x[N+cur+temp]+1)%4;
                temp++;
            }
            cur+=m-1;
            r= max(r,cur);  
        }
         if(n=='L')
        {
            int temp=0;
            while(temp<m)
            {
                x[N+cur-temp]=(x[N+cur-temp]+1)%4;
                temp++;
            }
            cur-=m-1;
            l= min(l,cur);  
        }
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        if(x[N+i]==1)
        {
            ans++;
        }
    }
    cout<<ans;
}
 