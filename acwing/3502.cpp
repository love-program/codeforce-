//题目要点总结：由于答案至少是 k+1 位数，所以需要从每个点开始进行深度优先搜索，直到走完 k 步。每次走一步都将当前数字添加到答案字符串中，走完后将其存入集合中以去重。使用 set 来存储不同的数字组合。
// 所以是dfs(i,j,0) 代表从(i,j)开始走0步，走完k步后将其存入集合中。同时在主函数中初始化ans
#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<vector<int>> mat;
set<string> res;
string ans;
vector<vector<int>> idx(4, vector<int>(2));

void dfs(int x, int y,int step)
{
   
    if(step==k)
    {
        res.insert(ans);
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx = x + idx[i][0];
        int ny = y + idx[i][1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            ans.append(to_string(mat[nx][ny]));
            dfs(nx , ny, step + 1);
            ans.pop_back();
        }
    }
}

int main() {
    // Your code here
    
    cin >> n >> m >> k;

    mat.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    idx[0] = {-1, 0};
    idx[1] = {1, 0};
    idx[2] = {0, -1};
    idx[3] = {0, 1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = ""; // 清空 ans
            ans.append(to_string(mat[i][j]));
            dfs(i,j,0);
        }
    }
    cout<<res.size()<<endl;
    // for(auto &s : res) {
    //     cout << s << endl; // 输出所有不同的数字组合
    // }
    return 0;
}
 // #include <bits/stdc++.h>
// using namespace std;

// int n, m, k;
// vector<vector<int>> mat;
// set<string> res;
// string ans;
// vector<vector<int>> idx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 上下左右方向

// void dfs(int x, int y, int step) {
//     if (step == k) { // 走完 k 步，形成 (k+1) 位数
//         res.insert(ans); // 插入到 set，自动去重
//         return;
//     }
//     for (int i = 0; i < 4; i++) {
//         int nx = x + idx[i][0];
//         int ny = y + idx[i][1];
//         if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
//             ans += to_string(mat[nx][ny]); // 添加当前数字
//             dfs(nx, ny, step + 1);
//             ans.pop_back(); // 回溯，移除最后一位
//         }
//     }
// }

// int main() {
//     cin >> n >> m >> k;
//     mat.resize(n, vector<int>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> mat[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             ans = ""; // 清空 ans
//             ans += to_string(mat[i][j]); // 添加起点数字
//             dfs(i, j, 0); // 从 step=0 开始
//         }
//     }
//     cout << res.size() << endl; // 输出不同数字的个数
//     return 0;
// }   