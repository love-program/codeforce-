#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        set<ll> res;  // 用set自动去重并排序
        
        ll pow10 = 10;  // 10^1，k从1开始
        while (true) {
            ll s = 1 + pow10;  // s = 1 + 10^k
            if (s > n) break;  // s超过n时，x会小于1，无效
            
            if (n % s == 0) {
                ll x = n / s;
                res.insert(x);  // 存储x而不是s
            }
            
            // 防止下一次pow10 *=10时溢出
            if (pow10 > LLONG_MAX / 10) break;
            pow10 *= 10;
        }
        
        if (res.empty()) {
            cout << 0 << '\n';
        } else {
            cout << res.size() << '\n';
            for (ll x : res) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
