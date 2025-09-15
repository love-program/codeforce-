#include <iostream>

// 函数用于解决单个测试用例
void solve() {
    long long x;
    std::cin >> x;
    
    // 根据数学推导，y = 2x 永远是一个有效的解
    long long y = 2 * x;
    
    std::cout << y << std::endl;
}

int main() {
    // 优化C++标准库的输入输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}