//以邻接点最多的点为中心，排除掉与它相连的叶子结点，寻找其余的叶子节点的数量大小
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    // 使用邻接表和度数数组来存储树的信息
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

    // 对于 n<=2 的情况，直径已经是最小的，不需要操作
    if (n <= 2) {
        std::cout << 0 << "\n";
        return;
    }

    // --- 步骤 1: 找到度数最大的节点作为中心点 ---
    int center_node = 1;
    for (int i = 2; i <= n; ++i) {
        if (degree[i] > degree[center_node]) {
            center_node = i;
        }
    }
    
    // --- 步骤 2: 统计所有不与中心点直接相连的叶子节点的数量 ---
    int misplaced_leaves = 0;
    for (int i = 1; i <= n; ++i) {
        // 首先，检查节点 i 是否是一个叶子节点
        if (degree[i] == 1) {
            // 如果是叶子节点，它只有一个邻居。
            // 获取这个唯一的邻居。
            int its_only_neighbor = adj[i][0];
            
            // 检查这个邻居是否是我们的中心点
            if (its_only_neighbor != center_node) {
                // 如果不是，说明这是一个“错位的”叶子
                misplaced_leaves++;
            }
        }
    }

    std::cout << misplaced_leaves << "\n";
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
// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>

// // 使用全局变量或通过引用传递来累计操作次数
// int total_ops;
// // 邻接表
// std::vector<std::vector<int>> adj;

// /**
//  * @brief 判断一个子树是否为“长分支”（即非单个叶子节点）。
//  *        如果是，它就需要被上层的一次操作所覆盖。
//  *        同时，它会递归地为其内部的分支增加操作数。
//  * 
//  * @param u 当前节点
//  * @param p 父节点
//  * @return bool 如果u的子树（不含p方向）是一个“长分支”，则返回true。
//  */
// bool is_long_branch_dfs(int u, int p) {
//     // 标记u是否有子节点（即不是一个孤立的叶子）
//     bool has_children = false;

//     // 遍历u的所有邻居
//     for (int v : adj[u]) {
//         if (v == p) {
//             continue; // 跳过父节点
//         }
        
//         has_children = true; // 发现了一个子节点

//         // 递归调用。如果子节点v的子树是一个"长分支"，
//         // 意味着在u->v这个分支内部，又出现了新的分叉，需要一次独立操作。
//         if (is_long_branch_dfs(v, u)) {
//             total_ops++;
//         }
//     }

//     // 如果u有任何子节点，它就构成了一个“长分支”的起点
//     return has_children;
// }

// void solve() {
//     int n;
//     std::cin >> n;

//     // 根据n的大小调整邻接表和度数数组
//     adj.assign(n + 1, std::vector<int>());
//     std::vector<int> degree(n + 1, 0);

//     for (int i = 0; i < n - 1; ++i) {
//         int u, v;
//         std::cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//         degree[u]++;
//         degree[v]++;
//     }

//     // 节点数小于等于2时，直径最小，无需操作
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
    
//     // --- 步骤 2: 使用DFS计算操作次数 ---
//     total_ops = 0; // 重置计数器

//     // 从选定的中心点开始，检查每一个分支
//     for (int neighbor : adj[center_node]) {
//         // 如果从中心点出发到这个邻居的分支是一个“长分支”，
//         // 那么就需要一次基础的操作来修复它。
//         if (is_long_branch_dfs(neighbor, center_node)) {
//             total_ops++;
//         }
//     }

//     std::cout << total_ops << "\n";
// }

// int main() {
//     // 加速C++的I/O
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int t;
//     std::cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }
