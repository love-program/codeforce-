#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[10][10] = {0};
string s;

bool dfs(int x, int y) {
    if (y == 10) return true; // 列超出，数独解决
    if (x == 10) return dfs(1, y + 1); // 行超出，进入下一列
    if (a[x][y] != 0) return dfs(x + 1, y); // 当前格子已填，跳到下一行

    bool st[10] = {false}; // 初始化所有数字为不可用
    fill(st + 1, st + 10, true); // 设置 1-9 为可用

    // 检查行、列和 3x3 子网格
    for (int i = 1; i <= 9; i++) {
        if (a[x][i] != 0) st[a[x][i]] = false; // 检查行
        if (a[i][y] != 0) st[a[i][y]] = false; // 检查列
        int subgrid_x = (x - 1) / 3 * 3 + (i - 1) / 3 + 1;
        int subgrid_y = (y - 1) / 3 * 3 + (i - 1) % 3 + 1;
        if (a[subgrid_x][subgrid_y] != 0) st[a[subgrid_x][subgrid_y]] = false; // 检查子网格
    }

    // 尝试填入数字 1-9
    for (int i = 1; i <= 9; i++) {
        if (st[i]) {
            a[x][y] = i;
            if (dfs(x + 1, y)) return true;
            a[x][y] = 0; // 回溯
        }
    }
    return false; // 所有数字都尝试失败
}

int main() {
    // 输入数独
    for (int i = 1; i <= 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            if (s[j] == '.') a[i][j + 1] = 0;
            else a[i][j + 1] = s[j] - '0';
        }
    }

    // 运行 DFS
    dfs(1, 1);

    // 输出结果
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// const int N = 10;
// int a[10][10]={0};
// string s;
// bool dfs(int x,int y)
// {
//    if(y==10) return true;
//    if(x==10) return dfs(1,y+1);
//    if(a[x][y]!=0) return dfs(x+1,y);

//    bool st[N]={true};//存还能填那些数（选择）
//    for(int i=1;i<10;i++)
//    {
//        if(a[x][i]!=0) st[a[x][i]]=false;
//        if(a[i][y]!=0) st[a[i][y]]=false;
//        if(a[(x-1)/3*3+i/3+1][(y-1)/3*3+i%3+1]!=0) st[a[(x-1)/3*3+i/3+1][(y-1)/3*3+i%3+1]]=false;
//    }
//     for(int i=1;i<10;i++)
//     {
//          if(st[i])
//          {
//               a[x][y]=i;
//               if(dfs(x+1,y)) return true;
//               a[x][y]=0;
              
//          }
         
//          return false;
//     }
    
// }
// int main()
// {
   
//     //初始化数据
//     for(int i=1;i<10;i++)
//     {
//         cin>>s;
//         for(int j=0;j<9;j++)
//         {
//             if(s[j]=='.') a[i][j+1]=0;
//             else a[i][j+1]=s[j]-'0';
//         }
//     }
//     // for(int i=1;i<10;i++)
//     // {
//     //     for(int j=1;j<10;j++)
//     //     {
//     //        cout<<a[i][j]<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     dfs(1,1);
//     for(int i=1;i<10;i++)
//     {
//         for(int j=1;j<10;j++)
//         {
//             cout<<a[i][j];
//         }
//         cout<<endl;
//     }



// }