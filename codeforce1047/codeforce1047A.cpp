#include<bits/stdc++.h> // 你原来的头文件
using namespace std;

int main()
{
    // 建议1：添加这两行来加速输入和输出，在处理大量数据时效果明显
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;

        // 建议2：用位运算替代 pow 函数
        // 使用 b * (1LL << a) 来计算 b * 2^a
        cout << b * (1LL << a) << endl;
    }
    // 建议3：main函数最好有一个返回值
    return 0;
}