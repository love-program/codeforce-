#include <bits/stdc++.h>
using namespace std;

void dfs(int index, int removed_count, int k, vector<int>& a, int n, vector<bool>& used, set<int>& mex_values) {
    // 如果已经移除 k 个元素，计算 MEX
    if (removed_count == k) {
        vector<bool> present(n + 1, false);
        // 统计剩余元素的频率
        for (int i = 0; i < n; i++) {
            if (!used[i] && a[i] <= n) {
                present[a[i]] = true;
            }
        }
        // 计算 MEX
        int mex = 0;
        while (mex <= n && present[mex]) {
            mex++;
        }
        mex_values.insert(mex);
        return;
    }
    
    // 如果索引超出数组大小，停止递归
    if (index == n) {
        return;
    }
    
    // 选择不移除当前元素
    dfs(index + 1, removed_count, k, a, n, used, mex_values);
    
    // 选择移除当前元素
    used[index] = true;
    dfs(index + 1, removed_count + 1, k, a, n, used, mex_values);
    used[index] = false; // 回溯
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 对于每个 k，计算可能的 MEX 值
    for (int k = 0; k <= n; k++) {
        set<int> mex_values; // 存储可能的 MEX 值
        vector<bool> used(n, false); // 标记哪些元素被移除
        dfs(0, 0, k, a, n, used, mex_values);
        cout << mex_values.size() << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}