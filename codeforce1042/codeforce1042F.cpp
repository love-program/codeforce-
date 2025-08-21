//答案错误（WA）
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        vector<int> prea(n + 1, 0), preb(n + 1, 0);

        // Calculate prefix differences for a and b
        for (int i = 1; i <= n; ++i) {
            prea[i] = prea[i - 1] + (a[i - 1] == '0' ? 1 : -1);
            preb[i] = preb[i - 1] + (b[i - 1] == '1' ? 1 : -1);
        }

        // Sort prefix arrays
        sort(prea.begin(), prea.end());
        sort(preb.begin(), preb.end());

        // Calculate the sum of absolute differences using two pointers
        ll sum_abs_diff = 0;
        int i = 0, j = 0;
        while (i <= n && j <= n) {
            if (prea[i] < preb[j]) {
                sum_abs_diff += preb[j] - prea[i];
                ++i;
            } else {
                sum_abs_diff += prea[i] - preb[j];
                ++j;
            }
        }

        // Calculate the final result
        ll total_sum = (ll)n * n * (n + 1) / 2;
        ll result = total_sum - sum_abs_diff / 2;

        cout << result << '\n';
    }

    return 0;
}