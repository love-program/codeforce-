#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> freq(n+1, 0);
        // 修改部分：将基于范围的for循环改为传统索引循环
        for (int i = 0; i < n; i++) {
            if (a[i] <= n) {
                freq[a[i]]++;
            }
        }

        vector<bool> ok(n+2, false);
        ok[0] = true;
        for (int m = 1; m <= n+1; m++) {
            if (m-1 <= n) {
                if (ok[m-1] && freq[m-1] >= 1) {
                    ok[m] = true;
                } else {
                    ok[m] = false;
                }
            } else {
                ok[m] = false;
            }
        }

        vector<int> d(n+2, 0);
        for (int m = 0; m <= n; m++) {
            if (!ok[m]) continue;
            int low = freq[m];
            int high = n - m;
            if (low <= high) {
                d[low]++;
                if (high+1 <= n+1) {
                    d[high+1]--;
                }
            }
        }

        vector<int> ans(n+1, 0);
        int cur = 0;
        for (int k = 0; k <= n; k++) {
            cur += d[k];
            ans[k] = cur;
        }

        for (int k = 0; k <= n; k++) {
            cout << ans[k];
            if (k < n) {
                cout << ' ';
            } else {
                cout << '\n';
            }
        }
    }
    return 0;
}
