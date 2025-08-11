
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 使用 long long 来避免溢出
using ll = long long;

void solve() {
    int n;
    ll x, y;
    cin >> n >> x >> y;

    // 使用 map 来统计频率，避免内存问题
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        counts[val]++;
    }

    // 将 map 转换为 vector of pairs 以便排序和处理
    vector<pair<int, int>> sorted_counts;
    for (auto const& [val, count] : counts) {
        sorted_counts.push_back({val, count});
    }

    int m = sorted_counts.size();
    vector<int> prefix_sum(m, 0);
    vector<int> suffix_max(m + 1, 0);

    // 计算前缀和
    prefix_sum[0] = sorted_counts[0].second;
    for (int i = 1; i < m; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + sorted_counts[i].second;
    }

    // 计算后缀最大值
    for (int i = m - 1; i >= 0; --i) {
        suffix_max[i] = max(suffix_max[i + 1], sorted_counts[i].second);
    }

    // Case 1: k = 0 (只使用替换操作)
    // 找到原始数组中的最大频率
    int max_freq_initial = suffix_max[0];
    ll min_cost = (ll)(n - max_freq_initial) * y;
    
    // 另一个只替换的策略：把所有数都变成0，如果0不在数组里，成本是 n*y
    // 如果0在数组里，成本是 (n-counts[0])*y。
    // 我们的k=0策略已经包含了这种情况，因为我们会找频率最高的数，如果0频率最高，就会被选中。
    min_cost = min(min_cost, (ll)n * y);


    // Case 2: k > 0 (减法+替换)
    // 遍历所有 unique 的值为 k
    for (int i = 0; i < m; ++i) {
        ll k = sorted_counts[i].first;
        
        // 成本 = 减法成本 + 替换成本
        ll current_cost = k * x;

        // F_k 是变成0的数的数量和剩下数中最大频率的较大者
        int freq_at_zero = prefix_sum[i];
        int max_freq_positive = suffix_max[i + 1];
        int Fk = max(freq_at_zero, max_freq_positive);
        
        current_cost += (ll)(n - Fk) * y;

        min_cost = min(min_cost, current_cost);
    }
    
    // 还有一个最终情况：把所有数都变成0
    // 需要 max(a_i) 次操作。这在我们的循环里已经隐式地包含了。
    // 比如当 k = 最后一个 unique 值 v_m 时，pref_sum[m-1] = n, suff_max[m] = 0. F_k=n.
    // 成本为 v_m * x.

    cout << min_cost << endl;
}

int main() {
    // 提高 IO 效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// int ans = 1e7;
// int main()
// {
//     int k;
//     cin >> k;
//     while (k--)
//     {
//         int n, a, b;
//         int max_n = 0;
//         cin >> n >> a >> b;
//         vector<int>number;
//         vector<int>freq(1e8);
//         set<int> p;
//         int max_freq = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int temp;
//             scanf("%d",&temp);
//             max_n = max(max_n, temp);
//             freq[temp]++;
//             p.insert(temp);
//         }
//         int temp = p.size();
//         for (int i = 0; i < temp; i++)
//         {
//             int cur = *p.begin();
//             number.push_back(cur);
//             max_freq = max(max_freq, freq[cur]);
//             p.erase(p.begin());
//         }
//         ans = 2e5;
//         ans = min(ans, b * (n - max_freq));
//         int cur_freq = 0;
//         for (int i = 0; i < number.size(); i++)
//         {
//             cur_freq += freq[number[i]];
//             if (cur_freq <= max_freq)
//             {
//                 continue;
//             }
//             max_freq = cur_freq;
//             ans = min(ans, number[i] * a + b * (n - max_freq));
//         }
//         cout << ans << endl;
//     }
// }
