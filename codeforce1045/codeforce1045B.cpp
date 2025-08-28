#include <iostream>
#include <vector>
#include <numeric>

// 性能优化
void setup_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// 解决单个测试用例的函数
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<long long> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    
    long long target_p = 0;

    for (long long p : small_primes) {
        if (k % p != 0) {
            target_p = p;
            break;
        }
    }
    
    
    // if (target_p == 0) { 
    //     target_p = 2; 
    // }

    for (int i = 0; i < n; ++i) {
        // 在一个有界的、短的循环中寻找 c
        for (long long c = 0; c < target_p; ++c) {
            if ((a[i] + c * k) % target_p == 0) {
                std::cout << a[i] + c * k << (i == n - 1 ? "" : " ");
                break; // 找到了最小的 c，处理下一个 a[i]
            }
        }
    }
    std::cout << std::endl;
}

int main() {
    setup_io();
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// using namespace std;
// // 为了提高性能，尤其是在处理大量输入时
// void setup_io() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
// }

// // 解决单个测试用例的函数
// void solve() {
//     int n;
//     long long k;
//     cin >> n >> k;
//     vector<long long> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }

//     if (k % 2 != 0) {
//         for (int i = 0; i < n; ++i) {
//             if (a[i] % 2 == 0) {
//                 cout << a[i] << (i == n - 1 ? "" : " ");
//             } else {
//                 cout << a[i] + k << (i == n - 1 ? "" : " ");
//             }
//         }
//         cout << endl;
//         return;
//     }

//     // Case 2: k 是偶数
//     // 无法改变任何数的奇偶性。目标公约数 p 必须是奇数（除非所有数已是偶数）。
//     // 我们选择数组中的最小元素作为目标公约数 p。
//     // *min_element 在 <algorithm> 头文件中
//     long long p = *min_element(a.begin(), a.end());
//     if(p==1)
//     p+=k;
    
//     // 对于数组中的每一个元素 a[i]，我们都要把它变成 p 的倍数
//     for (int i = 0; i < n; ++i) {
//         // 我们需要找到最小的非负整数 c，使得 (a[i] + c * k) % p == 0
//         // 直接循环查找 c 即可
//         for (long long c = 0; ; ++c) {
//             if ((a[i] + c * k) % p == 0) {
//                 cout << a[i] + c * k << (i == n - 1 ? "" : " ");
//                 break; // 找到了最小的 c，处理下一个 a[i]
//             }
//         }
//     }
//     cout << endl;
// }

// int main() {
//     setup_io();
//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }