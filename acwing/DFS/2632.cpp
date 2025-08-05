// dfs(x, y, n) 回答了这样一个问题：“给你一块 x by y 的蛋糕，要你把它变成 n 块面积相等的小蛋糕，你采用最优策略，最后得到的 n 块蛋糕中，长宽比最大的那个是多少？”
// 如果 n=1: 任务完成，直接报告当前这块的长宽比。
// 如果 n>1:
// 尝试所有可能的分割方案（分成 i 块和 n-i 块）。重要的是，他的dfs更新有max函数包裹，只统计当前分割方案下的最大长宽比，所以说不会影响ans
// 对每个方案，尝试两种切法（横切和竖切）。
// 对于每种切法，都会产生两个子问题，递归地去问 dfs：“如果你要处理这个小一点的蛋糕，你能做到的最好结果是什么？”
// 一个切法的好坏，取决于它产生的两个子问题中，结果更差（max）的那个。
// 我们从所有可能的切法中，选那个结果最好（min）的，作为当前问题的答案返回。

#include<bits/stdc++.h>
using namespace std;

double a,b;int n;

double dfs(double x,double y,int n){
    if(n == 1) return max(y,x)/min(y,x);
    double ans = 1e12;
    for(int i=1;i<n;i++) ans = min({ans,max(dfs(x/n*i,y,i),dfs(x/n*(n-i),y,n-i)),max(dfs(x,y/n*i,i),dfs(x,y/n*(n-i),n-i))}); 
    return ans;
}
signed main(){
    cin >> a >> b >> n;
    printf("%.6lf",dfs(a,b,n));
    return 0;
}

