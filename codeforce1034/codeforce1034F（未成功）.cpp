#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> smallest_prime_factor;
void sieve(int max_n) {
    smallest_prime_factor.resize(max_n + 1);
    for (int i = 2; i <= max_n; ++i) {
        if (smallest_prime_factor[i] == 0) {
            smallest_prime_factor[i] = i;
            if (1LL * i * i <= max_n) {
                for (int j = i * i; j <= max_n; j += i) {
                    if (smallest_prime_factor[j] == 0) {
                        smallest_prime_factor[j] = i;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    sieve(100000);
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        
        vector<bool> used(n + 1, false);
        
        for (int p_factor = 2; p_factor <= n; ++p_factor) {
            if (smallest_prime_factor[p_factor] != p_factor) continue;
            
            vector<int> group;
            for (int x = p_factor; x <= n; x += p_factor) {
                if (!used[x]) {
                    group.push_back(x);
                }
            }
            
            if (group.size() >= 2) {
                for (size_t i = 0; i < group.size(); ++i) {
                    int next = (i + 1) % group.size();
                    swap(p[group[i]], p[group[next]]);
                    used[group[i]] = true;
                }
            }
        }

        vector<int> remaining;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                remaining.push_back(i);
            }
        }

        if (!remaining.empty()) {
            for (size_t i = 0; i < remaining.size(); ++i) {
                int next = (i + 1) % remaining.size();
                swap(p[remaining[i]], p[remaining[next]]);
            }
        }
        
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
    
    return 0;
}
