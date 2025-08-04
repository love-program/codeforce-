// #include<bits/stdc++.h>
// using namespace std;

// struct point
// {
//     int x;
//     point(int x) : x(x) {}
// };
// vector<point> points;
// vector<vector<int>> matrix;

// int main()
// {
//     int n,k;
//     cin >> n >> k;
//     points.resize(n);
//     string s;
//     cin >> s;
//     for(int i=0;i<n;i++)
//     {
//         points[i] = point(s[i] - '0');
//     }
//     matrix.resize(n+1);
//     for(int i=0;i<n;i++)
//     { 
//         int u,v;
//         cin >> u >> v;
//         matrix[u].push_back(v);
//         matrix[v].push_back(u);
//     }
//     string cmp="";
//     string input;
//     while(k--)
//     {
//         cin >> input;
        
//     }
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n, q;
string node_values_str;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> achievable_values;

void build_parents() {
    parent.assign(n + 1, 0);
    vector<bool> visited(n + 1, false);
    queue<int> q_bfs;

    q_bfs.push(1);
    visited[1] = true;
    parent[1] = 0; 

    while (!q_bfs.empty()) {
        int u = q_bfs.front();
        q_bfs.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q_bfs.push(v);
            }
        }
    }
}

int main() {

    cin >> n >> q;
    cin >> node_values_str;

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    build_parents();

    
    achievable_values.assign(1 << 21, false);

    
    for (int i = 1; i <= n; ++i) {
        int current_node = i;
        vector<int> path_nodes; 


        for (int step = 0; step < 21 && current_node != 0; ++step) {
            path_nodes.push_back(current_node);

            
            long long forward_val = 0; 
            long long backward_val = 0; 


            for (int j = path_nodes.size() - 1; j >= 0; --j) {
                int node_val = node_values_str[path_nodes[j] - 1] - '0';
                forward_val = (forward_val << 1) | node_val;
            }

  
            for (size_t j = 0; j < path_nodes.size(); ++j) {
                int node_val = node_values_str[path_nodes[j] - 1] - '0';
                backward_val = (backward_val << 1) | node_val;
            }
            

            if (forward_val < achievable_values.size()) {
                achievable_values[forward_val] = true;
            }
            if (backward_val < achievable_values.size()) {
                achievable_values[backward_val] = true;
            }
            
 
            current_node = parent[current_node];
        }
    }


    while (q--) {
        int x;
        cin >> x;
        if (x < achievable_values.size() && achievable_values[x]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}