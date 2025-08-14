// ### 主要改动总结

// -   **判断条件**：`if (n <= 2)` 被替换为 `if (n <= 3)`，并且为了程序的健壮性，增加了消耗掉后续输入的代码。
// -   **核心算法替换**：删除了寻找“度数最大节点”的贪心部分，替换为遍历所有节点以寻找“能连接最多叶子节点的节点”的完备性算法。
// -   **结果计算**：计算方式从 `misplaced_leaves` 变更为 `total_leaves - max_leaf_neighbors`，这直接反映了问题的最优解公式。

// 这个修改后的版本现在能够正确处理所有情况，其逻辑与那段更优的 Python 代码完全一致。
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    // 如果 n <= 3，答案总是 0。但是我们仍然需要读取边的输入，
    // 以免这些输入干扰到下一个测试用例。
    if (n <= 3) {
        // 读取并丢弃 n-1 行边的数据
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
        }
        std::cout << 0 << "\n";
        return;
    }

    // 使用邻接表和度数数组来存储树的信息 (保持1-based索引)
    std::vector<std::vector<int>> adj(n + 1);
    std::vector<int> degree(n + 1, 0);

    // 读取 n-1 条边，构建图并计算度数
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    // --- 新逻辑 步骤 1: 计算树中总的叶子节点数量 ---
    // 叶子节点是度数为 1 的节点。
    int total_leaves = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            total_leaves++;
        }
    }

    // --- 新逻辑 步骤 2: 找到任何一个节点能够连接的最多叶子节点的数量 ---
    int max_leaf_neighbors = 0;
    // 遍历图中每一个节点 u，把它当作潜在的中心点
    for (int u = 1; u <= n; ++u) {
        int current_leaf_neighbors = 0;
        // 遍历 u 的所有邻居 v
        for (int v : adj[u]) {
            // 检查邻居 v 是否是一个叶子节点
            if (degree[v] == 1) {
                current_leaf_neighbors++;
            }
        }
        // 更新我们找到的“最大相邻叶子数”
        max_leaf_neighbors = std::max(max_leaf_neighbors, current_leaf_neighbors);
    }
    
    // --- 新逻辑 步骤 3: 最终答案是 (总叶子数 - 最优中心能覆盖的叶子数) ---
    // 这个差值就是那些无论我们怎么选中心，都无法直接与中心相连的叶子数量，
    // 也就是我们最少需要移动的叶子数量。
    std::cout << total_leaves - max_leaf_neighbors << "\n";
}

int main() {
    // 加速C++的I/O操作
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


// //以邻接点最多的点为中心，排除掉与它相连的叶子结点，寻找其余的叶子节点的数量大小
// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>

// void solve() {
//     int n;
//     std::cin >> n;

//     // 使用邻接表和度数数组来存储树的信息
//     std::vector<std::vector<int>> adj(n + 1);
//     std::vector<int> degree(n + 1, 0);

//     // 读取 n-1 条边，构建图并计算度数
//     for (int i = 0; i < n - 1; ++i) {
//         int u, v;
//         std::cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         degree[u]++;
//         degree[v]++;
//     }

//     // 对于 n<=2 的情况，直径已经是最小的，不需要操作
//     if (n <= 2) {
//         std::cout << 0 << "\n";
//         return;
//     }

//     // --- 步骤 1: 找到度数最大的节点作为中心点 ---
//     int center_node = 1;
//     for (int i = 2; i <= n; ++i) {
//         if (degree[i] > degree[center_node]) {
//             center_node = i;
//         }
//     }
    
//     // --- 步骤 2: 统计所有不与中心点直接相连的叶子节点的数量 ---
//     int misplaced_leaves = 0;
//     for (int i = 1; i <= n; ++i) {
//         // 首先，检查节点 i 是否是一个叶子节点
//         if (degree[i] == 1) {
//             // 如果是叶子节点，它只有一个邻居。
//             // 获取这个唯一的邻居。
//             int its_only_neighbor = adj[i][0];
            
//             // 检查这个邻居是否是我们的中心点
//             if (its_only_neighbor != center_node) {
//                 // 如果不是，说明这是一个“错位的”叶子
//                 misplaced_leaves++;
//             }
//         }
//     }

//     std::cout << misplaced_leaves << "\n";
// }

// int main() {
//     // 加速C++的I/O操作
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int t;
//     std::cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }
