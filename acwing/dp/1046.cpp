//知识点：线性dp，先按照dp规则算出最终答案，再利用dp方程回溯找路径
/*注意到，在状态转移方程中dp[i][j] = max(dp[i - 1][j-1] + adj[i][j], dp[i][j - 1])
*当dp[i][j]为当前行遍历的第1个元素时，dp[i][i-1]需要设置为一个不可能的值（如-55），否则会出现错误的结果。
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        adj[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
        }
    }
    vector<vector<int>> dp(n + 1);
    dp[0].assign(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp[i].resize(m + 1, 0);
        dp[i][i-1]=-55;
        for (int j = i; j <= m - (n - i); j++)
        {
            dp[i][j] = max(dp[i - 1][j-1] + adj[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m]<<endl;
    //dp回溯
    vector<int> ans;
    for (int i = n, j = m; i >= 1; i--)
    {
        while (j >= 1 && dp[i][j] == dp[i][j - 1]) j--;
        ans.push_back(j);
        j--;
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
}