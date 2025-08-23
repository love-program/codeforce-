#include <bits/stdc++.h>
using namespace std;

// 将n转换为三进制字符串（高位在前）
string toBase3(int n) {
    if (n == 0) return "0";
    string s;
    while (n > 0) {
        s += (char)(n % 3 + '0');
        n /= 3;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s = toBase3(n);
        int len = s.size();
        long long ans = 0;
        for (int k = 0; k < len; ++k) {
            int cnt = s[k] - '0'; // 当前位的交易次数
            if (cnt == 0) continue;
            int x = len - 1 - k; // 对应的x值（3^x个西瓜的交易）
            long long cost;
            if (x == 0) {
                cost = 3; // x=0时，1个西瓜3 coins
            } else {
                // 计算3^(x-1)（整数幂）
                long long pow3 = 1;
                for (int i = 0; i < x - 1; ++i) {
                    pow3 *= 3;
                }
                cost = (9 + x) * pow3; // x≥1时的花费公式
            }
            ans += cnt * cost;
        }
        cout << ans << '\n';
    }
    return 0;
}
