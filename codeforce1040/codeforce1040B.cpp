#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    long long s;
    std::cin >> n >> s;
    std::vector<int> a(n);
    int count0 = 0, count1 = 0, count2 = 0;
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0) {
            count0++;
        } else if (a[i] == 1) {
            count1++;
            total_sum += 1;
        } else {
            count2++;
            total_sum += 2;
        }
    }

    if (s < total_sum) {
        // 如果目标和小于数组总和，Alice不可能达到
        // 任何排列方式都可以，这里我们输出原始数组
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
        return;
    }

    if (s == total_sum) {
        // Alice可以走简单路径 1->2->...->n，Bob无法阻止
        std::cout << -1 << std::endl;
        return;
    }

    // s > total_sum
    long long diff = s - total_sum;

    if (diff == 1) {
        // Bob可以通过将0和1分开来阻止Alice增加1
        // 例如，排列为 0...0 2...2 1...1
        // 这样最小的相邻和为2
        // 我们需要构造并输出这样一个排列
        for (int i = 0; i < count0; ++i) std::cout << 0 << " ";
        for (int i = 0; i < count2; ++i) std::cout << 2 << " ";
        for (int i = 0; i < count1; ++i) {
            std::cout << 1 << (i == count1 - 1 ? "" : " ");
        }
        std::cout << std::endl;

    } else { // diff >= 2
        // Alice可以组合出任何 >= 2 的增量，Bob无法阻止
        std::cout << -1 << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}