#include <iostream>
#include <vector>
#include <algorithm>

// 为了方便处理，定义一个结构体来存储边的信息
struct Edge {
    int u, v, id;
};

// 解决单个测试用例
void solve() {
    int n;
    std::cin >> n;
    
    // 使用邻接表来存储所有以 v 结尾的边 (u, v)
    // adj[v] 会存储一系列的 pair {u, id}
    std::vector<std::vector<std::pair<int, int>>> adj(2 * n + 1);
    int max_coord = 0;

    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[v].push_back({u, i + 1}); // 存储边的起点和1-based的原始ID
        if (v > max_coord) {
            max_coord = v;
        }
    }

    // dp[i] 存储在区间 [1, i] 内能获得的最大并集长度
    std::vector<long long> dp(max_coord + 1, 0);
    // choice[i] 存储得到 dp[i] 的决策：{前驱坐标, 边ID}
    // 如果边ID为0，表示决策来自 dp[i-1]
    std::vector<std::pair<int, int>> choice(max_coord + 1);

    for (int i = 1; i <= max_coord; ++i) {
        // 决策1: 不使用任何以 i 结尾的边
        dp[i] = dp[i-1];
        choice[i] = {i - 1, 0};

        // 决策2: 遍历所有以 i 结尾的边 (u, i)
        for (const auto& edge_info : adj[i]) {
            int u = edge_info.first;
            int id = edge_info.second;
            
            // 计算使用这条边能达到的新并集长度
            long long current_val = dp[u] + (long long)(i - u);

            // 如果这个选择更优，则更新 dp[i] 和 choice[i]
            if (current_val > dp[i]) {
                dp[i] = current_val;
                choice[i] = {u, id};
            }
        }
    }

    // 回溯以找出所选边的ID
    std::vector<int> result_indices;
    int curr = max_coord;
    while (curr > 0) {
        const auto& decision = choice[curr];
        int prev_coord = decision.first;
        int edge_id = decision.second;

        if (edge_id != 0) {
            result_indices.push_back(edge_id);
        }
        curr = prev_coord;
    }
    
    // 回溯得到的是反向的，需要翻转
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