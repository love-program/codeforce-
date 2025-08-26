//改进后超时代码
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 使用 long long 防止答案溢出
long long ans; 
int n;
string s; // 存储每个点的字符
vector<vector<int>> adj; // 邻接表来存储树
const string target = "SCCPC";

// dfs(u, p, len)
// u: 当前节点
// p: u 在搜索路径上的父节点，防止走回头路
// len: 当前已形成的路径长度
long long dfs(int u, int p, int len) {
    // 终止条件：已经找到一条长度为5的路径
    if (len == 5) {
        return 1;
    }

    long long count = 0;
    // 遍历当前节点 u 的所有邻居 v
    for (int v : adj[u]) {
        // 防止走回头路，v 不能是来时的父节点 p
        if (v == p) {
            continue;
        }

        // 检查邻居 v 的字符是否是目标字符串中下一位的字符
        // s 的下标是 0-based, 而 v 是 1-based, 所以用 v-1
        if (s[v - 1] == target[len]) {
            // 如果匹配，则继续从 v 往下搜索，路径长度+1
            count += dfs(v, u, len + 1);
        }
    }

    return count;
}

void solve() {
    cin >> n;
    cin >> s;

    adj.assign(n + 1, vector<int>()); // 清空并重置邻接表

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    // 遍历所有节点，看是否能作为起点'S'
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'S') {
            // 从字符为'S'的节点开始DFS
            // 初始父节点设为0 (一个无效节点)，初始路径长度为1
            ans += dfs(i, 0, 1);
        }
    }
    cout << ans << endl;
}

int main() {
    // 加速cin/cout
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>> mat;
// int circle_start;
// vector<bool> visited;
// string input;
// string cur;
// int ans;
// void check(int node)
// {
//     for (int i : mat[node])
//     {
//         if (!visited[i])
//             return;
//     }
//     if (cur == "SCCPC")
//     {
//         ans++;
//         return;
//     }
//     return;
// }
// void dfs(int node, int depth)
// {
//     if (depth == 5)
//     {
//         check(node);
//         return;
//     }
//     for (int neighbor : mat[node])
//     {
//        if(depth==4&&neighbor==circle_start)
//        {
//             visited[neighbor]=false;
//        } 
//         if (!visited[neighbor])
//         {
//             visited[neighbor] = true;
//             cur.push_back(input[neighbor]);
//             dfs(neighbor, depth + 1);
//             cur.pop_back();
//             visited[neighbor] = false;
//         }
//     }
// }
// int main()
// {
//     int k; cin >> k;
//     while (k--)
//     {
//         ans = 0;
//         mat.clear();
//         int n; cin >> n;
//         mat.resize(n + 1);
//         visited.resize(n + 1, false);
//         cin >> input;
//         for (int i = 1; i < n; i++)
//         {
//             int a, b; cin >> a >> b;
//             mat[a - 1].push_back(b - 1);
//             mat[b - 1].push_back(a - 1);
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (input[i] != 'S')
//                 continue;
//             circle_start = i;
//             cur = "";
//             visited[i] = true;
//             cur.push_back(input[i]);
//             dfs(i, 1);
//             visited[i] = false;
//         }
//         cout << ans << endl;
//     }

// }