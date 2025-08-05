// // codeforce1040C.cpp
// // Problem: C. Path Queries
// // 思路：从1开始找最长路径（dfs），每到一个新的点就更新当前路径的值（查找是否为环）,由于要输出索引，使用结构体数组记录路径
// #include<bits/stdc++.h>
// using namespace std;   
// vector<vector<int>> matrix;//邻接点矩阵，边的权值由两个点相减的绝对值决定
// struct edge
// {
//     int u, v, id; // u和v是边的两个端点，id是边的索引
//     edge(int _u, int _v, int _id) : u(_u), v(_v), id(_id) {}
// };
// int ans=0;
// void dfs(int )
// {
    
// }

// int main()
// {
//     int k;
//     cin>>k;
//     while(k--)
//     {
//         int n;
//         cin>>n;
//         matrix.resize(n+1);
//         vector<edge> edges; // 存储边的信息
//         for(int i=1;i<=n;i++)
//         {
//             int u,v;
//             cin>>u>>v;
//             edges.emplace_back(u, v, i);
//         }
//         dfs(0);
//     }
// }
#include <iostream>
#include <vector>
#include <algorithm>

// 存储边的信息：u, v是端点，id是原始输入索引
struct Edge {
    int u, v, id;
};

// 解决单个测试用例
void solve() {
    int n;
    std::cin >> n;
    
    // 使用邻接表来存储所有以 v 结尾的边 (u, v)
    // adj[v] 会存储一系列的 pair {u, id}，u是起点，id是边的原始索引
    std::vector<std::vector<std::pair<int, int>>> adj(2 * n + 1);
    int max_coord = 0; // 记录所有坐标中的最大值

    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[v].push_back({u, i + 1}); // 存储边的起点和1-based的原始ID
        if (v > max_coord) {
            max_coord = v;
        }
    }

    // dp[i] 存储在区间 [1, i] 内，通过选择构成森林的边集，能获得的最大并集长度
    std::vector<long long> dp(max_coord + 1, 0);
    
    // choice[i] 存储得到 dp[i] 的决策：{前驱坐标, 边ID}
    // 如果边ID为0，表示决策来自 dp[i-1]，即不选以i为终点的边
    std::vector<std::pair<int, int>> choice(max_coord + 1);

    for (int i = 1; i <= max_coord; ++i) {
        // 决策1: 不选择任何以 i 为右端点的边。
        // 此时最大长度等于在 [1, i-1] 上的最大长度。
        dp[i] = dp[i-1];
        choice[i] = {i - 1, 0}; // 记录决策：来自前一个坐标，没有选择边

        // 决策2: 遍历所有以 i 为右端点的边 (u, i)
        for (const auto& edge_info : adj[i]) {
            int u = edge_info.first;
            int id = edge_info.second;
            
            // 计算如果选择这条边 (u, i)，能得到的新的并集总长度
            // 这个长度等于 [1, u] 上的最优解 + 新增区间 [u, i] 的长度
            long long current_val = dp[u] + (long long)(i - u);

            // 如果这个选择比当前 dp[i] 的结果更优，则更新 dp[i] 和 choice[i]
            if (current_val > dp[i]) {
                dp[i] = current_val;
                choice[i] = {u, id}; // 记录决策：来自坐标u，选择了边id
            }
        }
    }

    // 回溯以找出所选边的ID
    std::vector<int> result_indices;
    int curr = max_coord; // 从最大坐标开始回溯
    while (curr > 0) {
        const auto& decision = choice[curr];
        int prev_coord = decision.first;
        int edge_id = decision.second;

        // 如果edge_id不为0，说明在这一步我们选择了一条边
        if (edge_id != 0) {
            result_indices.push_back(edge_id);
        }
        // 移动到做出当前决策的前一个状态
        curr = prev_coord;
    }
    
    // 回溯得到的是反向的路径，需要翻转得到正序
    std::reverse(result_indices.begin(), result_indices.end());

    // 输出结果
    std::cout << result_indices.size() << std::endl;
    for (size_t i = 0; i < result_indices.size(); ++i) {
        std::cout << result_indices[i] << (i == result_indices.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    // 提高C++ I/O效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}







































