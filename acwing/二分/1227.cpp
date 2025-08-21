#include <iostream>
using namespace std;

int const N = 100010;
int w[N], h[N];//存储长、宽
int n, k;

bool chack(int a)
{
    int num = 0;//记录分成长度为 a 的巧克力数量
    for (int i = 0; i < n; i++)
    {
        num += (w[i] / a) * (h[i] / a);//每一大块可以分成的边长为 a 的巧克力数量
        if (num >= k) return true;//大于要求数量，返回真
    }
    return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> h[i] >> w[i];
    int l = 1, r = 1e5;//小巧克力数量边长一定在 1 -- 100000 之间
    while (l < r)//二分小巧克力边长范围，找到符合要求的最大值
    {
        int mid = l + ((r - l + 1) >> 1);//因为l = mid ，所以 mid 取 l + r + 1 >> 1,为了防止加和越界，改写成 l + (r - l + 1 >> 1)
        if (chack(mid)) l = mid;
        else r = mid - 1;
    }
    cout << r;
}
