#include<bits/stdc++.h> // 包含了所有标准库头文件
using namespace std;

int main()
{
    // 提高C++ IO效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while(n--)
    {
   
        long long l, r;
        cin >> l >> r;


        if(l == 1)
        {
            cout << "0" << endl;
        }

        else if(l == r) 
        {
            cout << "infty" << endl;
        }
        else
        {
            // --- 这是完善后的公式 ---
            // d 是区间的宽度 [l, r]
            long long d = r - l;

            // k0 是一个计算出的系数，代表需要多少轮区间合并才能填补所有空隙
            // (l - 2) / d 是整数除法
            long long k0 = (l - 2) / d + 1;

            // 应用推导出的数学公式直接计算结果
            // 该公式计算了初始的 l-1 个无法表示的数以及所有后续间隙中的数的总和
            long long total_unrepresentable = k0 * (l - 1) - d * k0 * (k0 - 1) / 2;

            cout << total_unrepresentable << endl;
        }
    }
    return 0;
}