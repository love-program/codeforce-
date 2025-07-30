#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include<bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    // ����Ƿ�ȫ0��ȫ1
    bool all_zero = true, all_one = true;
    for (char c : s) {
        if (c != '0') all_zero = false;
        if (c != '1') all_one = false;
    }
    if (all_zero || all_one) {
        cout << -1 << endl;
        return 0;
    }

    // ��ͼ�ͼ������
    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int j = (i + 1) % n;
            adj[i].push_back(j);
            in_degree[j]++;
        } else {
            int j = (i + 1) % n;
            adj[j].push_back(i);
            in_degree[i]++;
        }
    }

    // ��������
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // ����Ƿ���ڻ�
    if (topo_order.size() != n) {
        cout << -1 << endl;
        return 0;
    }

    // ����������
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[topo_order[i]] = i;
    }

    // ������
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
