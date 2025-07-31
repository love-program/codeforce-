#include <bits/stdc++.h>
using namespace std;

int n, m;
long long res = 0; // 方案数，注意可能较大，使用 long long
vector<vector<bool>> adj; // 邻接矩阵存储朋友关系
vector<int> perm; // 当前排列
vector<bool> used; // 标记编号是否使用

// 检查两个编号是否为朋友
bool is_friend(int x, int y) {
    return adj[x][y];
}

// DFS 生成排列，cur 表示当前填第 cur 个位置（1-based）
void dfs(int cur) {
    if (cur > n) {
        // 检查首尾是否为朋友
        if (!is_friend(perm[1], perm[n])) {
            res++;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            // 检查与前一个位置是否为朋友（cur > 1 时）
            if (cur == 1 || !is_friend(perm[cur-1], i)) {
                used[i] = true;
                perm[cur] = i;
                dfs(cur + 1);
                used[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    // 初始化
    adj.assign(n + 1, vector<bool>(n + 1, false));
    perm.assign(n + 1, 0);
    used.assign(n + 1, false);

    // 读取朋友关系
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = true; // 无向图
    }

    // 固定第一个位置为 1，消除旋转等价
    perm[1] = 1;
    used[1] = true;
    dfs(2);

    // 总方案数除以 N（旋转等价）
    cout << res << endl;

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int m,n;
//  int res = 0;
//     vector<int> a(m+1,0);
//     vector<int> b(m+1,0);
//     vector<bool> check(m+1,true);
//  void dfs(int x, int y,vector<int>& b,vector<bool>& check)
//     {
        
//         if(x>y&&a[b[y]]!=1)
//         { 

//             res++;
//             return;
//         }
//         else if(x>y)
//         {
//             return;
//         }
        
//         for(int i = 2; i <= y; i++)
//         {
            
//             if(a[x-1] != i && check[i])
//             {
                
//                 b[x] = i;
//                 check[i] = false;
              
//                 dfs(x+1,y,b,check);
//                 b[x] = 0;
//                 check[i] = true;
//             }
//         }
//     }
// int main()
// {
    
//     cin >> m >> n;
   
//     for(int i = 1; i <= m; i++)
//     {
//         int cur;
//         cin>>cur;
//         cin>>a[cur];
//         a[a[cur]] = cur;
//     }
    
//     dfs(2,m,b,check);
//     cout<<res;
    
// }