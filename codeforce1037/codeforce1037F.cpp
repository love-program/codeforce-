#include <bits/stdc++.h>
using namespace std;

vector<int> a;                  // 节点颜色
vector<int> parv;               // 父节点
vector<long long> costv;        // 边(parv[v], v)的权重
vector<vector<int>> children;   // 子节点列表
vector<unordered_map<int, long long>> mem;  // mem[v][c]：v到颜色为c的子节点的总权重
long long ans;                  // 当前答案


// DFS预处理父节点、子节点、costv和mem
void dfs(int u, int p, const vector<vector<pair<int, long long>>>& adj) {
    parv[u] = p;
    for (auto& [v, c] : adj[u]) {
        if (v != p) {  // v是u的子节点
            children[u].push_back(v);
            costv[v] = c;  // 边(u, v)的权重记录在子节点v上
            dfs(v, u, adj);
            // 初始化mem[u]：累加子节点v的颜色对应的权重
            mem[u][a[v]] += c;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // 建图：adj[u]存储(子节点, 权重)
        vector<vector<pair<int, long long>>> adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            long long c;
            cin >> u >> v >> c;
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }

        // 初始化父节点、子节点、costv、mem
        parv.resize(n + 1);
        children.resize(n + 1);
        costv.resize(n + 1);
        mem.assign(n + 1, unordered_map<int, long long>());
        dfs(1, -1, adj);  // 根节点1的父节点为-1（无效）

        // 计算初始ans
        ans = 0;
        for (int v = 2; v <= n; v++) {  // 非根节点
            int p = parv[v];
            if (a[v] != a[p]) {
                ans += costv[v];
            }
        }

        // 处理查询
        while (q--) {
            int v, x;
            cin >> v >> x;
            int old = a[v];
            if (old == x) {  // 颜色不变，直接输出
                cout << ans << '\n';
                continue;
            }

            // 步骤1：处理v到子节点的边
            ans += mem[v][old];   // 旧颜色为old的子节点的边变为收费
            ans -= mem[v][x];     // 新颜色为x的子节点的边变为免费

            // 步骤2：处理v与父节点的边（若v不是根）
            if (v != 1) {
                int p = parv[v];
                long long w = costv[v];
                // 移除旧状态的贡献
                if (old != a[p]) {
                    ans -= w;
                }
                // 添加新状态的贡献
                if (x != a[p]) {
                    ans += w;
                }
                // 更新父节点p的mem
                mem[p][old] -= w;
                mem[p][x] += w;
            }

            // 更新v的颜色
            a[v] = x;
            cout << ans << '\n';
        }
    }

    return 0;
}

/*
以下是未优化代码
*/
// #include<bits/stdc++.h>
// using namespace std;

// struct Point {
//     int color;
//     Point(int a) : color(a) {}
// };
// vector<Point> points; 
// struct Edge {
//     int u, v;
//     long long c;
//     bool active;  
    
//     Edge(int a, int b, long long c_val) : u(a), v(b), c(c_val) {
    
//         active = (points[a].color != points[b].color)?true : false;
//     }
// };


// vector<Edge> edges;    
// vector<vector<int>> adj;  

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int n, q;
//         cin >> n >> q;
        
        
//         points.clear();
//         edges.clear();
//         adj.assign(n + 1, vector<int>());  
        
        
//         points.push_back(Point(0));  
//         for(int i = 1; i <= n; i++) {
//             int color;
//             cin >> color;
//             points.push_back(Point(color));
//         }
        
        
//         long long total = 0;  
//         for(int i = 0; i < n - 1; i++) {
//             int u, v;
//             long long c;
//             cin >> u >> v >> c;
//             edges.push_back(Edge(u, v, c));
//             adj[u].push_back(i);  
//             adj[v].push_back(i);  
               
//             if(edges[i].active) {
//                 total += c;
//             }
//         }
//         for(int i = 0; i < q; i++) {
//             int v, new_color;
//             cin >> v >> new_color;
//             int old_color = points[v].color;
            
//             if(old_color == new_color) {
//                 cout << total << endl;
//                 continue;
//             }
//             points[v].color = new_color;
//             for(int edge_idx : adj[v]) {
//                 Edge& e = edges[edge_idx];
//                 int other = (e.u == v) ? e.v : e.u;  
//                 bool old_active = e.active;
//                 bool new_active = (new_color != points[other].color);
//                 if(old_active != new_active) {
//                     if(new_active) {
//                         total += e.c;  
//                     } else {
//                         total -= e.c;  
//                     }
//                     e.active = new_active;  
//                 }
//             }
            
            
//             cout << total << endl;
//         }
//     }
//     return 0;
// }