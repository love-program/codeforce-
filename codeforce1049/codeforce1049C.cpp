#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

const long long INF = 4e18; // 使用一个足够大的数表示无穷大

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long initial_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if ((i + 1) % 2 != 0) { // 奇数索引 (1-based)
            initial_sum += a[i];
        } else { // 偶数索引 (1-based)
            initial_sum -= a[i];
        }
    }

    long long max_gain = 0;

    // 情况 1: 同奇偶性交换
    // 奇数-奇数交换
    int last_odd = -1;
    if (n % 2 != 0) last_odd = n;
    else if (n >= 2) last_odd = n - 1;
    if (last_odd >= 3) {
        max_gain = max(max_gain, (long long)last_odd - 1);
    }
    // 偶数-偶数交换
    int last_even = -1;
    if (n % 2 == 0) last_even = n;
    else if (n >= 3) last_even = n - 1;
    if (last_even >= 4) {
        max_gain = max(max_gain, (long long)last_even - 2);
    }

    // 情况 2: l-odd, r-even
    long long min_l_plus_2a = INF;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) { // l is odd
            min_l_plus_2a = min(min_l_plus_2a, (long long)i + 2 * a[i - 1]);
        } else { // r is even
            if (min_l_plus_2a != INF) {
                long long current_gain = ((long long)i + 2 * a[i - 1]) - min_l_plus_2a;
                max_gain = max(max_gain, current_gain);
            }
        }
    }

    // 情况 3: l-even, r-odd
    long long min_l_minus_2a = INF;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 == 0) { // l is even
             min_l_minus_2a = min(min_l_minus_2a, (long long)i - 2 * a[i - 1]);
        } else { // r is odd
            if (min_l_minus_2a != INF) {
                long long current_gain = ((long long)i - 2 * a[i - 1]) - min_l_minus_2a;
                max_gain = max(max_gain, current_gain);
            }
        }
    }

    cout << initial_sum + max_gain << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}