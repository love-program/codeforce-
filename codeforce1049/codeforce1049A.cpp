#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

// 函数用于解决单个测试用例
void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // 1. 计算字符串中 '0' 的总数
    int zero_count = 0;
    for (char c : s) {
        if (c == '0') {
            zero_count++;
        }
    }

    // 如果没有 '0' 或没有 '1'，字符串已经是有序的
    if (zero_count == 0 || zero_count == n) {
        std::cout << 0 << std::endl;
        return;
    }

    // 2. 统计在前 zero_count 个位置中，有多少个 '1'
    // 这些 '1' 是错位的，必须被移走
    int misplaced_ones = 0;
    for (int i = 0; i < zero_count; ++i) {
        if (s[i] == '1') {
            misplaced_ones++;
        }
    }

    // 3. 错位'1'的数量就是最少操作数
    std::cout << misplaced_ones << std::endl;
}

int main() {
    // 优化C++标准库的输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}