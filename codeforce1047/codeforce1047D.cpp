#include <iostream>
#include <vector>
#include <algorithm>

// 将解决逻辑封装在函数中，便于处理多测试用例
void solve() {
    int n;
    std::cin >> n;
    
    // 使用 pair 存储 b 的值和它的原始索引
    std::vector<std::pair<int, int>> b_pairs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b_pairs[i].first; // b[i] 的值
        b_pairs[i].second = i;       // 原始索引 i
    }

    // 根据 b 的值进行排序，这样值相同的元素会聚集在一起
    std::sort(b_pairs.begin(), b_pairs.end());

    // --- 验证阶段 ---
    bool possible = true;
    for (int i = 0; i < n; ) {
        int current_val = b_pairs[i].first;
        
        // 找到当前值所在组的结尾
        int j = i;
        while (j < n && b_pairs[j].first == current_val) {
            j++;
        }
        
        int count = j - i; // 这个组的大小
        if (count % current_val != 0) {
            possible = false;
            break;
        }
        i = j; // 跳转到下一个组
    }

    if (!possible) {
        std::cout << -1 << std::endl;
        return;
    }

    // --- 构造阶段 ---
    std::vector<int> a(n);
    int val_to_assign = 1;
    for (int i = 0; i < n; ) {
        int current_b_val = b_pairs[i].first;
        
        // 找到当前组的结尾
        int j = i;
        while (j < n && b_pairs[j].first == current_b_val) {
            j++;
        }
        
        // 遍历这个组，以 current_b_val 为大小分块赋值
        for (int k = i; k < j; ++k) {
            int original_index = b_pairs[k].second;
            a[original_index] = val_to_assign;
            
            // 每分配完一个大小为 current_b_val 的块，就用一个新的值
            if ((k - i + 1) % current_b_val == 0) {
                val_to_assign++;
            }
        }
        i = j; // 跳转到下一个组
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    // 加速 C++ 的 I/O 操作
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}