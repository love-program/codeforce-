#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 计算0到n的所有数字的数字总和
ll count_sum(ll n) {
    if (n < 0) return 0;
    ll sum = 0;
    ll pos = 1;  // 10^0，从个位开始处理
    while (pos <= n) {
        ll high = n / (pos * 10);  // 高位部分
        ll curr = (n / pos) % 10;  // 当前位数字
        ll low = n % pos;          // 低位部分
        // 高位完整周期的和
        sum += high * 45 * pos;
        // 当前位从0到curr-1的和
        sum += (curr * (curr - 1) / 2) * pos;
        // 当前位为curr时，低位所有可能的和
        sum += (low + 1) * curr;
        pos *= 10;  // 处理更高位
    }
    return sum;
}

ll solve(ll k) {
    ll total = 0;
    int d = 1;                  // 当前位数
    ll start = 1;               // 当前位数的起始数字（10^(d-1)）
    ll bits = 9;                // 当前位数的总位数（d×9×10^(d-1)）

    // 累加完整位数的数字和
    while (k > bits) {
        ll end = start * 10 - 1;  // 当前位数的结束数字（10^d - 1）
        total += count_sum(end) - count_sum(start - 1);  // 累加当前位数的和
        k -= bits;                // 减去当前位数的总位数
        d++;                      // 进入下一位数
        start *= 10;
        bits = 9 * d * start;     // 更新下一位数的总位数
    }

    // 处理当前位数的剩余部分
    ll m = k / d;                // 完整的d位数个数
    ll r = k % d;                // 剩余的位数（不足一个d位数）
    ll end = start + m - 1;      // 最后一个完整的d位数
    total += count_sum(end) - count_sum(start - 1);  // 累加这些d位数的和

    // 处理剩余的r位（取下一个d位数的前r位）
    if (r > 0) {
        ll x = start + m;
        string s = to_string(x);
        for (int i = 0; i < r; ++i) {
            total += s[i] - '0';
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        cout << solve(k) << '\n';
    }
    return 0;
}