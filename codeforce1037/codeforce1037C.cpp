#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        int h0 = h[k - 1];
        int max_h = *max_element(h.begin(), h.end());

        if (h0 == max_h) {
            cout << "YES\n";
            continue;
        }

        set<int> s(h.begin(), h.end());
        vector<int> sorted_s(s.begin(), s.end());

        int current = h0;
        bool possible = false;

        while (true) {
            if (current == max_h) {
                possible = true;
                break;
            }
            int upper = current + h0;
            if (upper > max_h) {
                upper = max_h;
            }
            
            vector<int>::iterator it = upper_bound(sorted_s.begin(), sorted_s.end(), upper);
            if (it == sorted_s.begin()) {
                break;
            }
            --it;
            if (*it <= current) {
                break;
            }
            current = *it;
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}
