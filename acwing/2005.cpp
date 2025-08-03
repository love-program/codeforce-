//注意dfs的使用场景，则终止条件，回溯方法等也会有不一样的地方
#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> mats;
int step = 1;
int max1 = 0;
vector<vector<bool>> visited;
string ans = " ";
bool is_valid(string s)
{
    int k = 1;
    while (s[k] == '(')
    {
        k++;
    }
    for (int i = k; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            return false;
        }
    }

    if ((k-1) * 2 > s.size()-1)
    {
        return true;
    }
    else if ((k-1) * 2 == s.size()-1)
    {
        max1 = max(max1, (k-1) * 2);

    }
    else
    {
        return false;
    }
}

vector<int> x_directions = { 0,0,1,-1 };
vector<int> y_directions = { 1,-1,0,0 };
void dfs(int x, int y)
{
   
   
    if (!is_valid(ans))
    {
        return;
    }


    for (int i=0;i<4;i++)
    {
        int nx = x + x_directions[i];
        int ny = y + y_directions[i];
        
        if (nx < 1 || nx > mats.size() - 1 || ny < 1 || ny > mats[0].size() - 1||visited[nx][ny])
        {
            continue;
        }
        ans += mats[nx][ny];
        visited[nx][ny] = true;
        dfs(nx,  ny);
        ans.pop_back();
        visited[nx][ny] = false;
    }

}
int main()
{
    int n;
    cin >> n;
    mats.resize(n + 1, vector<char>(n + 1));

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 1; j <= n; j++)
        {
            cin >> mats[i][j];
        }
    }
    if (mats[1][1] == ')')
    {
        cout << "0" << endl;
        return 0;
    }
    visited.resize(n + 1, vector<bool>(n + 1, false));
    ans += '(';
    dfs(1, 1);
    cout << max1 << endl;
}
// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>

// using namespace std;

// // 全局变量，与您的原始代码结构保持一致
// int n;
// vector<vector<char>> mats;
// vector<vector<bool>> visited;
// string ans = "";
// int max1 = 0;

// // 方向数组，用于向上下左右移动
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};

// // 深度优先搜索函数
// void dfs(int x, int y) {
//     // --- 1. 验证当前路径并更新最大长度 ---
//     int open = 0, close = 0;
//     bool closing_phase = false; // 是否已经开始出现 ')'

//     for (char c : ans) {
//         if (c == '(') {
//             // 如果已经出现了')'，但又遇到了'('，说明路径无效
//             if (closing_phase) {
//                 return;
//             }
//             open++;
//         } else {
//             closing_phase = true;
//             close++;
//         }
//     }

//     // 如果')'的数量超过'('，路径无效
//     if (close > open) {
//         return;
//     }

//     // 如果左右括号数相等，说明形成了一个完全平衡字符串
//     // 用它的长度更新最大值
//     if (open == close) {
//         max1 = max(max1, (int)ans.length());
//     }


//     // --- 2. 探索所有可能的下一步 ---
//     for (int i = 0; i < 4; ++i) {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         // 检查邻居是否在边界内，并且之前没有访问过
//         if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !visited[nx][ny]) {
            
//             visited[nx][ny] = true;      // 标记：进入新格子
//             ans.push_back(mats[nx][ny]); // 更新路径

//             dfs(nx, ny); // 递归搜索

//             // 回溯：撤销刚才的选择，尝试其他可能性
//             ans.pop_back();              // 恢复路径
//             visited[nx][ny] = false;     // 取消标记
//         }
//     }
// }

// int main() {
//     // 使用 std::ios::sync_with_stdio(false); cin.tie(0); 可以加速输入输出
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n;
//     mats.resize(n + 1, vector<char>(n + 1));
//     visited.resize(n + 1, vector<bool>(n + 1, false));


//     for (int i = 1; i <= n; ++i) {
//         string row;
//         cin >> row;
//         for (int j = 1; j <= n; ++j) {
//             mats[i][j] = row[j - 1];
//         }
//     }


//     if (mats[1][1] == ')') {
//         cout << 0 << endl;
//         return 0;
//     }

    
//     ans += mats[1][1];
//     visited[1][1] = true;
    
//     dfs(1, 1);

//     cout << max1 << endl;

//     return 0;
// }