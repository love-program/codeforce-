#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // 提高输入输出效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n % 2 != 0) {
        // 如果 n 是奇数, 最大公约数为 1.
        // 字典序最小的排列是 1, 2, 3, ..., n.
        for (int i = 1; i <= n; ++i) {
            std::cout << i << (i == n ? "" : " ");
        }
        std::cout << std::endl;
    } else {
        // 如果 n 是偶数, 最大公约数为 2.
        // 字典序最小的排列是通过两两交换得到的: 2 1, 4 3, ...
        for (int i = 1; i <= n; i += 2) {
            std::cout << i + 1 << " " << i << (i + 1 == n ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> ans ;
// vector<int> cur ;
// int max_gcd=0;
// int n;
// vector<int>vis;

// void solve()
// {
//     int a = 1 * cur[0];
//     for (int i = 0; i < n; i++)
//     {
//         a = __gcd(a, (i+1)* cur[i]);
//         if(a<max_gcd)
//         {
//             return;
//         }
//     }
//     if (a > max_gcd)
//     {
//         max_gcd = a;
//         ans = cur;
//     }
// }
// void dfs(int step)
// {
//     if (step == n)
//     {
//         solve();
//         return;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i] == 1)
//         {
//             continue;
//         }
//         vis[i] = 1;
//         cur.push_back(i);
//         dfs(step + 1);
//         vis[i] = 0;
//         cur.pop_back();
//     }
// }
// int main()
// {

//     cin >> n;
//     vis.assign(n + 1, 0);
//     dfs(0);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",ans[i]);
//     }
// }