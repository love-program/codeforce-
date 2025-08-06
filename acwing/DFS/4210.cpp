#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int a;
string res;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void dfs(int n)
{
    if (n == a)
    {
        return;
    }
    int cur = a;
    while (cur >= n)
    {
        ans += cur % n;
        cur = (cur - cur % n) / n;
    }
    if (cur != 0)
    {
        ans += cur;
    }
    dfs(n + 1);
}
int main()
{

    cin >> a;
    dfs(2);
    cout << ans / gcd(ans, a - 2) << "/" << (a - 2) / gcd(ans, a - 2) << endl;
    return 0;

}