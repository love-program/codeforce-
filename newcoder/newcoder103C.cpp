// #include <iostream>

// // 使用 long long 来防止中间计算过程中的整数溢出
// using ll = long long;

// // 定义模数常量，方便使用和修改
// const int MOD = 1e9 + 7;


// ll power(ll base, ll exp) {
//     ll res = 1;
//     base %= MOD; // 先对底数取模

//     while (exp > 0) {
//         // 如果指数是奇数，那么我们需要乘上一个底数
//         // (对应二进制位为1)
//         if (exp % 2 == 1) {
//             res = (res * base) % MOD;
//         }

//         // 底数平方，为下一次迭代做准备
//         // (a^(2k) = (a^k)^2)
//         base = (base * base) % MOD;

//         // 指数除以2（或右移一位）
//         // (相当于处理二进制的下一位)
//         exp /= 2;
//     }
//     return res;
// }

// int main() {

//     ll n;
//     std::cin >> n;

//     // 处理特殊情况 n = 1，此时指数为 0
//     if (n == 1) {
//         std::cout << 1 << std::endl;
//         return 0;
//     }

//     // 根据我们的推导，答案是 2^(n-1)
//     ll result = power(2, n - 1);

//     std::cout << result << std::endl;

//     return 0;
// }
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long res = 0;
long long n;
vector<long long> a; 
vector<bool> used;   
const int MOD = 1e9 + 7;


bool is_good_optimized() {

    if (n == 1) return true;


    vector<int> positions(n + 1);
    for (int i = 1; i <= n; ++i) {
        positions[a[i]] = i; // positions[数值] = 索引
    }
    int l = positions[1];
    int r = positions[1];

    for (int k = 2; k <= n; ++k) {
        int current_pos = positions[k];
        if (current_pos == l - 1) {
            l = current_pos;
        } else if (current_pos == r + 1) {
            r = current_pos;
        } else {
            return false;
        }
    }


    return true;
}


void dfs(int pos) {
    if (pos > n) {

        if (is_good_optimized()) {
            res = (res + 1) % MOD;
        }
        return;
    }

    for (int num = 1; num <= n; ++num) {
        if (!used[num]) {
            a[pos] = num;
            used[num] = true;
            dfs(pos + 1);
            used[num] = false;
        }
    }
}

int main() {
    cin >> n;
    
    a.assign(n + 1, 0);
    used.assign(n + 1, false);

    dfs(1);
    
    cout << res << endl;
    return 0;
}