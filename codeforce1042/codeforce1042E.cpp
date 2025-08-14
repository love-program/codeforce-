// #include <iostream>
// #include <vector>
// #include <numeric>

// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<long long> a(n);
//     std::vector<long long> b(n);
//     for (int i = 0; i < n; ++i) std::cin >> a[i];
//     for (int i = 0; i < n; ++i) std::cin >> b[i];

//     // 1. 检查最后一个元素
//     if (a[n - 1] != b[n - 1]) {
//         std::cout << "NO\n";
//         return;
//     }

//     // 2. 从后往前检查每个位置的可能性(更贴近于题目的逻辑)
//     for (int i = n - 2; i >= 0; --i) {
//         if (a[i] == b[i]) {
//             // 不需要操作，直接满足
//             continue;
//         } else {
//             // 必须操作，检查两种可能的操作时机
//             bool possible = false;
//             // 可能1: op(i) 在 op(i+1) 之前执行
//             if ((a[i] ^ a[i + 1]) == b[i]) {
//                 possible = true;
//             }
//             // 可能2: op(i) 在 op(i+1) 之后执行 (a[i+1]已变为b[i+1])
//             if ((a[i] ^ b[i + 1]) == b[i]) {
//                 possible = true;
//             }
            
//             if (!possible) {
//                 std::cout << "NO\n";
//                 return;
//             }
//         }
//     }

//     std::cout << "YES\n";
// }

// int main() {
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     int t;
//     std::cin >> t;
//     while (t--) {
//         solve();
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<long long>a(n + 1);
        vector<long long>b(n + 1);
        vector<long long> qu;
        for (int i = 1; i <= n; i++)
        {
            //scanf("%lld", &a[i]);
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            //scanf("%lld", &b[i]);
            cin >> b[i];
            if (a[i] != b[i])
                qu.push_back(i);
        }
        if (a[n] != b[n])
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            bool check = true;
            for(int i:qu)
            {
                if((a[i]^a[i+1])==b[i]||((a[i]^b[i+1])==b[i]))
                {
                    check=true;
                }
                else{
                    check=false;
                    break;
                }
            }
            if (check)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

        }
    }
}