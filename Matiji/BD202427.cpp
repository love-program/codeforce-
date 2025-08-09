#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int fx[] = {1,0,-1,0};
int fy[]={0,1,0,-1};
int n,x1,y_1,x2,y2;
bool g[N][N];
int dp[N][N];
queue<pair<int,int>>qu;
int bs;
void dfs(int x,int y)
{
    if(x<0||x>1001||y<0||y>1001)return;
    if(dp[x][y]!=-1)return;
    dp[x][y]=bs;
    if(g[x][y]==1)
    {
        qu.push({x,y});
        return;
    }
    for(int i=0;i<4;i++)
    {
        dfs(x+fx[i],y+fy[i]);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>x1>>y_1>>x2>>y2;
    memset(dp,-1,sizeof dp);
    dp[x1][y_1]=0;
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
    }
    qu.push({x1,y_1});
    while(qu.size())
    {
        auto [x,y] = qu.front();
        qu.pop();
        for(int i=0;i<4;i++)
        {
            bs=dp[x][y]+g[x][y];
            dfs(x+fx[i],y+fy[i]);
        }
    }
    cout<<dp[x2][y2]<<endl;
    return 0;
}

// //01bfs
// #include <iostream>
// #include <vector>
// #include <deque> // 使用双端队列 deque

// using namespace std;

// // 使用结构体可以让代码更清晰
// struct point {
//     int x;
//     int y;
// };

// const int N = 1002;

// // 全局变量与您的代码保持一致
// int n, x1, y_1, x2, y2;
// bool g[N][N]; // g[x][y] = true 表示(x,y)有冰柱
// vector<vector<int>> dp(N, vector<int>(N, -1)); // dp[x][y] 记录最小体力消耗

// // 4个移动方向
// int fx[] = {1, 0, -1, 0};
// int fy[] = {0, 1, 0, -1};

// int main() {
//     // 提高cin/cout效率
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n >> x1 >> y_1 >> x2 >> y2;

//     // 初始化冰柱位置
//     for (int i = 0; i < n; ++i) {
//         int r, c;
//         cin >> r >> c;
//         g[r][c] = true;
//     }

//     // 使用双端队列实现 0-1 BFS
//     deque<point> dq;

//     // 初始化起点
//     // 起点本身是可用的，代价为0
//     dp[x1][y_1] = 0;
//     dq.push_front({x1, y_1}); // 将起点加入队头

//     while (!dq.empty()) {
//         point curr = dq.front();
//         dq.pop_front();

//         int curr_cost = dp[curr.x][curr.y];

//         // 提前结束：如果当前处理的节点就是终点，
//         // 由于算法特性，此时的体力消耗一定是最少的。
//         if (curr.x == x2 && curr.y == y2) {
//             cout << curr_cost << endl;
//             return 0;
//         }

//         // 探索四个方向的邻居
//         for (int i = 0; i < 4; ++i) {
//             int next_x = curr.x + fx[i];
//             int next_y = curr.y + fy[i];

//             // 检查边界
//             if (next_x < 0 || next_x > 1001 || next_y < 0 || next_y > 1001) {
//                 continue;
//             }

//             // 计算到达邻居的代价
//             int cost_to_move = g[next_x][next_y] ? 1 : 0;
//             int new_total_cost = curr_cost + cost_to_move;

//             // 如果找到了更优的路径，或者第一次到达该邻居
//             if (dp[next_x][next_y] == -1 || new_total_cost < dp[next_x][next_y]) {
//                 dp[next_x][next_y] = new_total_cost;

//                 // 根据移动代价决定入队位置
//                 if (cost_to_move == 1) {
//                     // 代价为1的移动，放到队尾
//                     dq.push_back({next_x, next_y});
//                 } else {
//                     // 代价为0的移动，放到队头
//                     dq.push_front({next_x, next_y});
//                 }
//             }
//         }
//     }

//     // 题目保证一定能走到，所以循环内一定会找到终点并返回。
//     // 如果代码执行到这里，说明可能出现了意外情况。
//     // 但根据题目，我们最终会输出 dp[x2][y2]。
//     cout << dp[x2][y2] << endl;

//     return 0;
// }