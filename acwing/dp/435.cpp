//环形dp，i是第i次传球，j是当前球员位置
#include <iostream>

using namespace std;

const int N = 35;

int n, m;
int f[N][N];

int main()
{
    cin >> n >> m;

    f[0][0] = 1;
    for (int i = 1; i <= m; i ++ )
        for (int j = 0; j < n; j ++ )
            f[i][j] = f[i - 1][(j + n - 1) % n] + f[i - 1][(j + 1) % n];

    cout << f[m][0] << endl;

    return 0;
}
