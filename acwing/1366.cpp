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
// #include<bits/stdc++.h>
// using namespace std;
// string n;
// vector<bool> vis(1e7, false);
// bool is_number(string a)
// {
//     vector<bool>st(10, false);
//     for (int i = 0; i < a.size(); i++)
//     {
//         if (!st[a[i]-'0'])
//         {
//             st[a[i]-'0'] = true;
//         }
//         else
//             return false;
//     }
//     return true;
// }

// bool is_all_visited(string y)
// {
//     for (int i = 0; i < y.size(); i++)
//     {
//         if (!vis[i]) return false;
//     }
//     return true;
// }
// bool is_wanted(int x, string y)
// {
//     if (vis[x] && x != 0) return false;
//     else if (y[x]-'0' == 0) return false;
//     else if (x == 0 && is_all_visited(y)) return true;
  

//     vis[x] = true;
//     if (is_wanted((y[x] - '0'+x) % y.size(), y))
//         return true;
//     return false;
// }

// int main()
// {

//     cin >> n;
//     for (int i = stoi(n) + 1; i < 1e7; i++)
//     {
//         if(!is_number(to_string(i)))
//             continue;
//         vis.assign(1e7, false);
//         vis[0] = true;
//         string s = to_string(i);
//         if (is_wanted((s[0] - '0') % s.size(), s))
//         {
//             cout << i << endl;
//             return 0;
//         }
//     }
// }