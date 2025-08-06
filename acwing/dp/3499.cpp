//i:序列里的前 i 个数
//j:前i个数里删除的数字个数
//u:枚举a[i]前的最佳序列a[u]，u <= i - 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210;

int a[N], w[N][N], f[N][N];
int n, k, m;


int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i ++ )
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            cin >> w[i][j];

        }
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;

    for(int i = 1; i <= m; i++)//考虑前 i 个数，所以 i 从 1 到 m
    {
        for(int j = 0; j <= i - 1 && j <= k; j++)//删除的数字个数不能大于 数字个数 且 不能大于 k
            {
                for(int u = i - 1 - j; u <= i - 1; u++)//前
                {
                    f[i][j] = max(f[i][j], f[u][j - (i - 1 - u)] + w[a[u]][a[i]]);
                }
            }
    }
    int res = 0;
    for(int i = 0; i <= k; i++)
        res = max(res, f[m][i]);
    cout << res;
    return 0;

}
