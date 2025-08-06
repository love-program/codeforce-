#include<bits/stdc++.h>
using namespace std;
int ans = 0;
 int n,m;
vector<bool> visited;
vector<vector<int>> a;

void dfs(int n,int step)
{
    if (ans<step)
    {
        ans=step;
    }
    for(int i=0;i<a[n].size();i++)
    {
        int v = a[n][i];
        if (!visited[v])
        {
            visited[v] = true;
            dfs(v,step+1);
            visited[v] = false;
            // if(step==0) return; 遍历一个分支就结束
        }
    }
    return;
}
int main()
{
   
    cin >> n >> m;
   
    a.resize(n+1);
    for(int i = 1; i <= n; i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    visited.resize(n+1, false);
    visited[m] = true; // 从节点1开始
    dfs(m,0);
    cout << ans << endl;
    return 0;
}