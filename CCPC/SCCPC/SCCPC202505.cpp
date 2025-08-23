#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

// 为了方便，使用 bits/stdc++.h
// #include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> q_pos;
    vector<int> pref_ones(n + 1, 0);

    // 预处理：计算前缀 '1' 的数量，并记录 '?' 的位置
    for (int i = 0; i < n; ++i) {
        pref_ones[i + 1] = pref_ones[i];
        if (s[i] == '1') {
            pref_ones[i + 1]++;
        } else if (s[i] == '?') {
            q_pos.push_back(i);
        }
    }

    vector<int> suff_zeros(n + 1, 0);
    // 预处理：计算后缀 '0' 的数量
    for (int i = n - 1; i >= 0; --i) {
        suff_zeros[i] = suff_zeros[i + 1];
        if (s[i] == '0') {
            suff_zeros[i]++;
        }
    }

    int q_count = q_pos.size();

    // 计算基础情况：假设所有 '?' 都填充为 '0' 时的逆序对数
    long long current_inversions = 0;
    long long ones_count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones_count++;
        } else { // '0' 或 '?' (视为 '0')
            current_inversions += ones_count;
        }
    }

    long long max_inversions = current_inversions;

    // 迭代：依次将第 k 个 '?' 从 '0' 变为 '1'，并计算逆序对总数的变化
    // k 表示当前已经有多少个 '?' 被设置为了 '1'
    for (int k = 0; k < q_count; ++k) {
        int p = q_pos[k]; // 当前要从 '0' 变为 '1' 的 '?' 的位置

        // 当 s[p] 从 '0' 变为 '1' 时：
        // 1. 损失的逆序对：s[p] 不再与它前面的 '1' 构成逆序对。
        //    前面的 '1' 包括原序列中的 '1' 和之前被设置为 '1' 的 '?'
        long long original_ones_before = pref_ones[p];
        long long q_as_one_before = k;
        long long loss = original_ones_before + q_as_one_before;

        // 2. 增加的逆序对：s[p] 开始与它后面的 '0' 构成逆序对。
        //    后面的 '0' 包括原序列中的 '0' 和之后仍被视为 '0' 的 '?'
        long long original_zeros_after = (p + 1 < n + 1) ? suff_zeros[p + 1] : 0;
        long long q_as_zero_after = (q_count - 1 - k);
        long long gain = original_zeros_after + q_as_zero_after;
        
        // 更新当前的逆序对总数，并与最大值比较
        current_inversions = current_inversions + gain - loss;
        if (current_inversions > max_inversions) {
            max_inversions = current_inversions;
        }
    }

    cout << max_inversions << "\n";
}

int main() {
    // 快速 IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}