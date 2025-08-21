//答案错了，看不懂博弈论喵
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // 计算前缀和
        vector<ll> preA(n + 1, 0), preB(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            preA[i + 1] = preA[i] + a[i];
            preB[i + 1] = preB[i] + b[i];
        }

        ll mandy = a[0], brz = b[n - 1];
        // Mandy一直向右，brz一直向左
        ll mandy_right = preA[n] - a[0];
        ll brz_left = preB[n - 1];

        // Mandy和brz在中间相遇时的分数
        ll mandy_max = mandy, brz_max = brz;
        for (int i = 1; i < n; ++i) {
            // Mandy向右到i，brz向左到i
            ll mandy_score = preA[i + 1];
            ll brz_score = preB[n] - preB[i];
            mandy_max = max(mandy_max, mandy_score);
            brz_max = max(brz_max, brz_score);
        }

        if (mandy_max > brz_max) cout << "Mandy\n";
        else if (mandy_max < brz_max) cout << "brz\n";
        else cout << "draw\n";
    }
    return 0;
}