//三分搜索，通过对上下限的不断更新，不断刷新m1,m2三分点，将范围缩小到2找峰值
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

// 定义一个函数，方便计算 S(i) = prefix_a[i] + prefix_b[z - i]
ll get_sum(ll i, ll z, const vector<ll>& prefix_a, const vector<ll>& prefix_b) {
    ll j = z - i;
    // 这里的边界检查其实可以省略，因为三分搜索的范围已经保证了 i 和 j 的合法性
    // if (i < 0 || i >= prefix_a.size() || j < 0 || j >= prefix_b.size()) {
    //     return -1; 
    // }
    return prefix_a[i] + prefix_b[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll n, m, q;
        cin >> n >> m >> q;

        vector<ll> a(n);
        vector<ll> b(m);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());

        vector<ll> prefix_a(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix_a[i + 1] = prefix_a[i] + a[i];

        vector<ll> prefix_b(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefix_b[i + 1] = prefix_b[i] + b[i];

        while (q--) {
            ll x, y, z;
            cin >> x >> y >> z;

            // 确定从 a 中取牌数量 i 的合法范围 [low, high]
            ll low = max(0LL, z - y);
            ll high = min(x, z);

            // 如果合法范围不存在，结果为0
            if (low > high) {
                cout << 0 << '\n';
                continue;
            }

            // 对 i 在 [low, high] 范围内进行三分搜索
            while (high - low >= 3) {
                ll m1 = low + (high - low) / 3;
                ll m2 = high - (high - low) / 3;
                if (get_sum(m1, z, prefix_a, prefix_b) < get_sum(m2, z, prefix_a, prefix_b)) {
                    low = m1;
                } else {
                    high = m2;
                }
            }

            // 三分搜索结束后，最优解在 [low, high] 这个小区间内，暴力检查一下
            ll max_ans = 0;
            for (ll i = low; i <= high; ++i) {
                max_ans = max(max_ans, get_sum(i, z, prefix_a, prefix_b));
            }

            cout << max_ans << '\n';
        }
    }
    return 0;
}
//原来的线性搜素超时
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int k;
//     cin >> k;
//     while (k--)
//     {
//         ll n, m, q;
//         cin >> n >> m >> q;
        
//         vector<ll> a(n);
//         vector<ll> b(m);
        
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         for (int i = 0; i < m; i++)
//             cin >> b[i];
        
//         // 从大到小排序，方便取最大的元素
//         sort(a.begin(), a.end(), greater<ll>());
//         sort(b.begin(), b.end(), greater<ll>());
        
//         // 计算前缀和，prefix_a[i]表示取前i个a的总和
//         vector<ll> prefix_a(n + 1, 0);
//         for (int i = 0; i < n; i++)
//             prefix_a[i + 1] = prefix_a[i] + a[i];
        
//         // prefix_b[i]表示取前i个b的总和
//         vector<ll> prefix_b(m + 1, 0);
//         for (int i = 0; i < m; i++)
//             prefix_b[i + 1] = prefix_b[i] + b[i];
        
//         while (q--)
//         {
//             ll x, y, z;
//             cin >> x >> y >> z;
            
//             // 确定从a中取的卡片数量范围
//             ll min_a = max(0LL, z - y);  // 至少要从a取的数量
//             ll max_a = min(x, z);        // 最多能从a取的数量
            
//             ll ans = 0;
//             // 枚举所有可能的分配方案，找到最大和
//             for (ll i = min_a; i <= max_a; i++)
//             {
//                 ll j = z - i;  // 从b中取的数量
//                 if (j < 0 || j > y) continue;  // 确保b的数量合法
                
//                 ans = max(ans, prefix_a[i] + prefix_b[j]);
//             }
            
//             cout << ans << '\n';
//         }
//     }
//     return 0;
// }
