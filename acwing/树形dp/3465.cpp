#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
vector<int> dp; // 记录每个节点为起点的最长链长度
vector<int> pre; // 记录每个节点的最优后继
int n;

// 树形DP，返回以u为起点的最长链长度
int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    if (a[u].empty()) {
        dp[u] = 1;
        pre[u] = -1;
        return dp[u];
    }
    int maxlen = 0, minv = -1;
    for (int v : a[u]) {
        int len = dfs(v);
        if (len > maxlen) {
            maxlen = len;
            minv = v;
        } else if (len == maxlen && v < minv) {
            minv = v;
        }
    }
    dp[u] = maxlen + 1;
    pre[u] = minv;
    return dp[u];
}

int main() {
    cin >> n;
    a.resize(n);
    dp.assign(n, -1);
    pre.assign(n, -1);
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int y;
            cin >> y;
            a[i].push_back(y);
            indegree[y]++;
        }
        sort(a[i].begin(), a[i].end()); // 保证字典序
    }

    // 找源头节点（入度为0）
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            root = i;
            break;
        }
    }

    int len = dfs(root);
    cout << len << endl;

    // 回溯输出路径
    vector<int> res;
    int cur = root;
    while (cur != -1) {
        res.push_back(cur);
        cur = pre[cur];
    }
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    return 0;
}