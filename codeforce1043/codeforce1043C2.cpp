// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k;
//         cin >> n >> k;
//         vector<int> digits;
//         int temp = n;
//         // 将n转换为三进制，digits[i]表示3^i的系数
//         if (temp == 0) {
//             digits.push_back(0);
//         } else {
//             while (temp > 0) {
//                 digits.push_back(temp % 3);
//                 temp /= 3;
//             }
//         }
//         // 计算初始交易次数
//         int s = accumulate(digits.begin(), digits.end(), 0);
//         if (s > k) {
//             cout << -1 << '\n';
//             continue;
//         }
//         int rem = k - s; // 可额外使用的交易次数
//         long long ans = 0;
//         int m = digits.size();
//         // 计算初始花费
//         for (int i = 0; i < m; ++i) {
//             if (digits[i] == 0) continue;
//             if (i == 0) {
//                 ans += 3LL * digits[i];
//             } else {
//                 long long pow3 = 1;
//                 for (int j = 0; j < i - 1; ++j) {
//                     pow3 *= 3;
//                 }
//                 ans += digits[i] * (9 + i) * pow3;
//             }
//         }
//         // 从高位到低位拆分交易，最大化减少花费
//         for (int i = m - 1; i >= 1; --i) {
//             if (rem <= 0) break;
//             if (digits[i] == 0) continue;
//             // 计算拆分收益：delta = 3^(i-1)
//             long long delta = 1;
//             for (int j = 0; j < i - 1; ++j) {
//                 delta *= 3;
//             }
//             // 最多可拆分的次数
//             int max_t = min(digits[i], rem / 2);
//             if (max_t <= 0) continue;
//             // 更新花费、交易次数和剩余可使用次数
//             ans -= max_t * delta;
//             digits[i] -= max_t;
//             digits[i - 1] += 3 * max_t;
//             rem -= max_t * 2;
//         }
//         cout << ans << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// 快速计算3的x次幂（避免溢出）
long long pow3(int x) {
    if (x < 0) return 0;
    long long res = 1;
    for (int i = 0; i < x; ++i) {
        res *= 3;
    }
    return res;
}

// 将n转换为三进制数组（低位在前，digits[i]对应3^i的数量）
vector<int> toBase3(int n) {
    vector<int> digits;
    if (n == 0) {
        digits.push_back(0);
        return digits;
    }
    while (n > 0) {
        digits.push_back(n % 3);
        n /= 3;
    }
    return digits;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> digits = toBase3(n);
        int total_deals = accumulate(digits.begin(), digits.end(), 0); // 初始交易次数
        
        // 初始交易次数已超过k，不可能完成
        if (total_deals > k) {
            cout << -1 << '\n';
            continue;
        }
        
        int extra = k - total_deals; // 可额外增加的交易次数
        long long cost = 0;
        
        // 计算初始成本
        int m = digits.size();
        for (int i = 0; i < m; ++i) {
            if (digits[i] == 0) continue;
            if (i == 0) {
                cost += 3LL * digits[i]; // x=0时，每笔3 coins
            } else {
                cost += digits[i] * (9 + i) * pow3(i - 1); // x≥1时的成本公式
            }
        }
        
        // 从最高位往低位拆分（最大化节省成本）
        // 注意：这里不需要进位，允许低位数量超过3，因为我们需要增加交易次数
        for (int i = m - 1; i >= 1 && extra >= 2; --i) {
            if (digits[i] == 0) continue;
            
            // 最多可拆分的次数：不超过当前位数量，且不超过额外次数的一半
            int split = min(digits[i], extra / 2);
            if (split <= 0) continue;
            
            // 拆分逻辑：1笔i级交易 → 3笔i-1级交易
            digits[i] -= split;
            if (i - 1 >= digits.size()) {
                digits.push_back(3 * split); // 扩展数组（如果需要）
            } else {
                digits[i - 1] += 3 * split;
            }
            
            // 每次拆分节省 3^(i-1) 的成本
            cost -= split * pow3(i - 1);
            extra -= 2 * split; // 每次拆分增加2次交易
        }
        
        cout << cost << '\n';
    }
    return 0;
}
