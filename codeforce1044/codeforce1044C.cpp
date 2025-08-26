//交互题学习
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
void solve() {
    int n;
    cin >> n;

    vector<int> dist(n + 1);        

    for (int i = 1; i <= n; ++i) {
        cout << "? " << i << " " << n;
        for (int j = 1; j <= n; ++j) {
            cout << " " << j;
        }
        cout << endl; 
        fflush(stdout);
        cin >> dist[i];
    }

    vector<int> sorted_nodes(n);
    iota(sorted_nodes.begin(), sorted_nodes.end(), 1); 
    sort(sorted_nodes.begin(), sorted_nodes.end(), [&](int a, int b) {
        return dist[a] > dist[b];
    });
    vector<int> path;
    vector<bool> used_in_path(n + 1, false); 

    for (int start_node : sorted_nodes) {
        if (used_in_path[start_node]) {
            continue; 
        }

        path.clear();
        path.push_back(start_node);
        used_in_path[start_node] = true;

        int current_path_len = dist[start_node];

        while (path.size() < current_path_len) {
            int last_node = path.back();
            int next_node = -1;
            for (int candidate : sorted_nodes) {
                if (used_in_path[candidate]) {
                    continue;
                }
                
                if (dist[candidate] != dist[last_node] - 1) {
                    continue;
                }

                cout << "? " << last_node << " 2 " << last_node << " " << candidate << endl;
                int query_result;
                cin >> query_result;

                if (query_result == 2) {
                    next_node = candidate;
                    break;
                }
            }
            
            if (next_node != -1) {
                path.push_back(next_node);
                used_in_path[next_node] = true;
            } else {
                break;
            }
        }
        
        if (path.size() == dist[sorted_nodes[0]]) {
            break;
        }
    }

    std::cout << "! " << path.size();
    for (int node : path) {
        std::cout << " " << node;
    }
    std::cout << std::endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}