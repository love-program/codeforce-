//小姐：我的dfs做法答案正确但超时了，这题不需要算法，直接筛选就行了
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

// 检查一个数 n 是否是循环数
bool is_cyclic(int n) {
    std::string s = std::to_string(n);
    int len = s.length();

    // 步骤 1: 快速筛选。检查是否有 '0' 或重复数字。
    // 使用一个大小为 10 的数组来跟踪 1-9 的数字是否出现过。
    bool seen_digits[10] = {false}; 
    for (char c : s) {
        int digit = c - '0';
        if (digit == 0) {
            return false; // 循环数不含 0
        }
        if (seen_digits[digit]) {
            return false; // 循环数没有重复数字
        }
        seen_digits[digit] = true;
    }

    // 步骤 2: 检查循环路径
    std::vector<bool> visited_indices(len, false); // 只需 len 大小的向量
    int current_pos = 0; // 从最左边的位置（索引0）开始

    // 模拟跳转 len 次
    for (int i = 0; i < len; ++i) {
        // 如果在访问完所有数字前，就跳到了一个已经访问过的位置，则不是循环数
        if (visited_indices[current_pos]) {
            return false;
        }
        visited_indices[current_pos] = true; // 标记当前位置为已访问
        
        int jump_distance = s[current_pos] - '0';
        current_pos = (current_pos + jump_distance) % len;
    }

    // 经过 len 次不重复的跳转后，必须恰好回到起点（索引0）
    return current_pos == 0;
}

int main() {
    // 加快 C++ 的 I/O 速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    std::cin >> m;

    // 从 m+1 开始寻找
    for (int i = m + 1; ; ++i) {
        if (is_cyclic(i)) {
            std::cout << i << std::endl;
            break; // 找到第一个就退出
        }
    }

    return 0;
}
// #include <iostream>
// #include <string>
// #include <vector>
// #include <numeric>

// // 优化的DFS辅助函数
// // s: 数字字符串
// // visited: 记录位置是否被访问的数组
// // current_pos: 当前所在的位置（索引）
// // visited_count: 已经访问过的不同位置的数量
// bool check_cycle_dfs(const std::string& s, std::vector<bool>& visited, int current_pos, int visited_count) {
//     // 基本情况（递归终止条件）

//     // 1. 如果当前位置已经访问过
//     if (visited[current_pos]) {
//         // 检查这是否是成功的循环：
//         // 必须回到了起点(0)，并且所有位置都访问过了(visited_count == s.length())
//         return current_pos == 0 && visited_count == s.length();
//     }

//     // 递归步骤

//     // 标记当前位置为已访问
//     visited[current_pos] = true;
    
//     // 计算下一个位置
//     int jump_distance = s[current_pos] - '0';
//     int next_pos = (current_pos + jump_distance) % s.length();
    
//     // 进入下一层递归，已访问位置数量加一
//     return check_cycle_dfs(s, visited, next_pos, visited_count + 1);
// }

// // 主检查函数，负责设置并启动DFS
// bool is_cyclic(int n) {
//     std::string s = std::to_string(n);
//     int len = s.length();

//     // 优化点3：将检查前提化
//     // 首先检查数字本身是否有效（无'0'，无重复数字）
//     bool seen_digits[10] = {false};
//     for (char c : s) {
//         int digit = c - '0';
//         if (digit == 0 || seen_digits[digit]) {
//             return false; // 如果有'0'或重复数字，立即判定为无效
//         }
//         seen_digits[digit] = true;
//     }
    
//     // 优化点1：创建大小正确的visited数组
//     std::vector<bool> visited(len, false);
    
//     // 优化点2和4：从起点(0)开始，初始访问数量为0，启动DFS
//     return check_cycle_dfs(s, visited, 0, 0);
// }

// int main() {
//     // 加快C++ I/O
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);

//     int m;
//     std::cin >> m;

//     for (int i = m + 1; ; ++i) {
//         if (is_cyclic(i)) {
//             std::cout << i << std::endl;
//             break;
//         }
//     }

//     return 0;
// }