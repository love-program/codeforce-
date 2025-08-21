//在数组里面寻找值，而非操作
#include<iostream>
using namespace std;
const int N  = 1e5 + 10;
int s[N];
int n, m;
bool check(int mid)
{
    int cnt = 1;
    for(int i = 1, j = 1; i <= n; i++)
        if(s[i] - s[j - 1] > mid && (j = i))//若当前区间和大于结果，记录区间右界，寻找下一个区间
            if(++cnt > m)                   //计数超过m段，则结果偏小
                return false;
    return true;                            //反之偏大
}
void solve()
{
    int l = 0, r;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
        l = max(l, x);          //可能的结果最小为A中的最大值，可分成n段
    }
    r = s[n];                   //可能的结果最大为A所有数的和，可分成1段

    while(l < r)                //二分模板
    {
        int mid = l + r >> 1;   
        if(check(mid))          //结果偏大，更新右界
            r = mid;
        else
            l = mid + 1;        //反之更新左界
    }
    cout << l;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
