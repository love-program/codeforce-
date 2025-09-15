#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
queue<int>q;
vector<vector<int>>a;
int main()
{
    double k,m,n;
    cin>>k>>m>>n;
    a.resize(k);
    ans.resize(k,0);
    int start =0;
    for(int i=0;i<k;i++)
    {
        int k;
        cin>>k;
        if(k!=-1)
        {
            a[k].push_back(i);
        }
        else
        {
            start = i;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:a[u])
        {
           ans[v] = ans[u]+1;
            q.push(v);
        }
    }
    sort(ans.begin(),ans.end());
    int p=1;
    int res=ans.back();
    for(int i=ans.size()-2;i>=0;i--)
    {
        if(ans[i]==res)
        {
            p++;
        }
        else
        {
            break;
        }
    }
    double t=m;
    for(int i=0;i<res;i++)
    {
        t *= (1+n/100);
    }
    cout<<setprecision(2)<<fixed<<t<<' ';
    cout<<p<<endl;
    return 0;
}