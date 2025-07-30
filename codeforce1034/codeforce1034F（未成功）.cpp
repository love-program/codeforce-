#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算最小质因数
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
    
    // 预处理最小质因数数组（一次性处理所有可能的n）
    sieve(100000);
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1);  // 1-based排列
        
        // 初始化排列为p[i] = i
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
        }
        
        // 标记位置是否已处理
        vector<bool> used(n + 1, false);
        
        // 按最小质因数分组处理
        for (int p_factor = 2; p_factor <= n; ++p_factor) {
            if (smallest_prime_factor[p_factor] != p_factor) continue;  // 不是质数
            
            vector<int> group;
            for (int x = p_factor; x <= n; x += p_factor) {
                if (!used[x]) {
                    group.push_back(x);
                }
            }
            
            // 构造循环
            if (group.size() >= 2) {
                for (size_t i = 0; i < group.size(); ++i) {
                    int next = (i + 1) % group.size();
                    swap(p[group[i]], p[group[next]]);
                    used[group[i]] = true;
                }
            }
        }
        
        // 处理剩余未被处理的数（如1和质数）
        vector<int> remaining;
        for (int i = 1; i <= n; ++i) {
            if (!used[i]) {
                remaining.push_back(i);
            }
        }
        
        // 处理剩余数的循环
        if (!remaining.empty()) {
            for (size_t i = 0; i < remaining.size(); ++i) {
                int next = (i + 1) % remaining.size();
                swap(p[remaining[i]], p[remaining[next]]);
            }
        }
        
        // 输出排列
        for (int i = 1; i <= n; ++i) {
            cout << p[i] << (i == n ? '\n' : ' ');
        }
    }
    
    return 0;
}
