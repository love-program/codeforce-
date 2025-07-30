#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll find_min_q(ll l_val,  ll r_val, ll ban_val) {
    if (l_val > r_val) {
        return -1;
    }

    ll non_ban_mask = ~ban_val;
    non_ban_mask &= ((1LL << 61) - 1);

    ll q_val = 0;

    for (int i = 60; i >= 0; i--) {
        ll bit = (1LL << i);
        ll low_mask = bit - 1;
        ll low_mask_val = low_mask & non_ban_mask;
        ll high_bound = q_val | low_mask_val;

        if (high_bound < l_val) {
            if (ban_val & bit) {
                return -1;
            } else {
                q_val |= bit;
                if (q_val > r_val) {
                    return -1;
                }
            }
        } else {
        }
    }

    if (q_val < l_val) {
        return -1;
    }
    return q_val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, l_val, r_val, k;
        cin >> n >> l_val >> r_val >> k;

        if (n == 1) {
            if (l_val <= r_val) {
                cout << l_val << '\n';
            } else {
                cout << "-1\n";
            }
            continue;
        }

        if (n % 2 == 1) {
            if (l_val <= r_val) {
                cout << l_val << '\n';
            } else {
                cout << "-1\n";
            }
        } else {
            if (n % 4 != 0) {
                if (l_val <= 0 && 0 <= r_val) {
                    cout << 0 << '\n';
                } else {
                    cout << "-1\n";
                }
            } else {
                ll p_val = l_val;
                ll q_val = find_min_q(l_val, r_val, p_val);
                if (q_val == -1) {
                    cout << "-1\n";
                } else {
                    ll half = n / 2;
                    if (k <= half) {
                        cout << p_val << '\n';
                    } else {
                        cout << q_val << '\n';
                    }
                }
            }
        }
    }
    return 0;
}
