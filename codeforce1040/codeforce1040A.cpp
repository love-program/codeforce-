#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> S(n);
        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }
        sort(S.begin(), S.end());

        long long score = 0;
        int zeros = 0;
        for (int x : S) {
            if (x == 0) zeros++;
        }
        score += zeros; // 取所有 0，mex = 1 每次 +1
        vector<int> remaining;
        for (int x : S) {
            if (x != 0) remaining.push_back(x);
        }
        if (!remaining.empty()) {
            score += accumulate(remaining.begin(), remaining.end(), 0LL);
        }
        cout << score << "\n";
    }
    return 0;
}