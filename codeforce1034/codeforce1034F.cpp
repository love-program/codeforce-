#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1); // 1-based permutation
        vector<bool> used(n + 1, false);

        // Step 1: Set p[1] = 1 (one fixed point)
        p[1] = 1;
        used[1] = true;

        // Step 2: Construct the rest of the permutation
        for (int i = 2; i <= n; i++) {
            // Find a number that is not coprime with i
            for (int j = 1; j <= n; j++) {
                if (!used[j] && __gcd(j, i) > 1) {
                    p[i] = j;
                    used[j] = true;
                    break;
                }
            }
            // If no suitable j found, use the next available number
            // (though with n <= 10^5, a suitable j should always exist)
            if (!used[p[i]]) {
                for (int j = 1; j <= n; j++) {
                    if (!used[j]) {
                        p[i] = j;
                        used[j] = true;
                        break;
                    }
                }
            }
        }

        // Output the permutation
        for (int i = 1; i <= n; i++) {
            cout << p[i] << (i == n ? "\n" : " ");
        }
    }
    return 0;
}