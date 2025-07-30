#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long INF = 1LL << 60;
    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a == b) {
            cout << 0 << endl;
            continue;
        }
        vector<long long> dp(201, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
        dp[a] = 0;
        pq.push(make_pair(0, a));
        long long ans = INF;
        while (!pq.empty()) {
            pair<long long, int> top = pq.top();
            long long cost = top.first;
            int u = top.second;
            pq.pop();
            if (cost != dp[u]) continue;
            if (u == b) {
                ans = cost;
                break;
            }
            if (u + 1 <= 200) {
                long long new_cost = cost + x;
                if (new_cost < dp[u + 1]) {
                    dp[u + 1] = new_cost;
                    pq.push(make_pair(new_cost, u + 1));
                }
            }
            int nx = u ^ 1;
            if (nx >= 0 && nx <= 200) {
                long long new_cost = cost + y;
                if (new_cost < dp[nx]) {
                    dp[nx] = new_cost;
                    pq.push(make_pair(new_cost, nx));
                }
            }
        }
        if (ans == INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
