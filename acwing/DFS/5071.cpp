//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//const int N = 210;
//
//int n;
//int w[N], cnt;// w[]存储每一堆石子数量 cnt是石子堆的个数
//int m, d;// 答案M 和 D
//
//int getd()//求最大石子堆石子数量与最小石子堆石子数量之差
//{
//    int x = 0, y = N;
//    for (int i = 0; i < cnt; i++)
//    {
//        x = max(x, w[i]);
//        y = min(y, w[i]);
//    }
//    return x - y;
//}
//
//void dfs()
//{
//    if (cnt > m) m = cnt, d = getd();//现在的石子堆数>上一次的，更新M和D
//    else if (cnt == m) d = min(d, getd());//相等只更新 D
//
//    if (cnt == 1)//只有一堆的情况
//    {
//        int a = w[0];
//        for (int x = a / 3 + 1; x <= a / 2; x++)
//        {
//            w[0] = x;
//            w[cnt++] = a - x;
//            dfs();
//            //恢复现场
//            w[0] = a;
//            cnt--;
//        }
//    }
//    else
//    {
//        int i = 0, j = -1;
//        for (int k = 1; k < cnt; k++)//找到第一，第二大的值的下标
//            if (w[k] >= w[i]) j = i, i = k;
//            else if (j == -1 || w[k] > w[j]) j = k;
//
//        int a = w[i], b = w[j];
//        if (a > b)
//        {
//            for (int x = max(b / 2, a / 3) + 1; x <= a / 2; x++)
//            {
//                w[i] = x, w[cnt++] = a - x;
//                dfs();
//                //恢复现场
//                w[i] = a, cnt--;
//            }
//        }
//        else return;
//    }
//}
//
//int main()
//{
//    cin >> n;
//    w[cnt++] = n;//初始化只有一堆，w[0]=n,cnt=1
//
//    dfs();//暴力枚举所有方案数
//
//    cout << m << " " << d << endl;
//    return 0;
//}


 #include <bits/stdc++.h>
using namespace std;

const int N=120;
int n;
int m = 1;
int d = INT_MAX; // 使用 INT_MAX 替代 10000，避免边界问题
int cur = 1;
vector<int> a(N, 0); // 固定大小，避免动态 resize 问题，N=210

int getd() {
    int max_val = 0, min_val = INT_MAX;
    for (int i = 0; i < cur; i++) {
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
    }
    return max_val - min_val;
}

void dfs() {
    if (cur > m) {
        m = cur;
        d = getd();
    } else if (cur == m) {
        d = min(d, getd()); // 取最小 D
    }
    if (cur == 1) {
        int c = a[0];
        for (int x = c / 3 + 1; x <= c / 2; x++) {
            a[0] = x;
            a[cur++] = c - x;
            dfs();
            // 恢复现场
            a[0] = c;
            cur--;
        }
    } else {
        int i = 0, j = -1;
        for (int k = 1; k < cur; k++) { // 找到第一，第二大的值的下标
            if (a[k] >= a[i]) j = i, i = k;
            else if (j == -1 || a[k] > a[j]) j = k;
        }
        int a_val = a[i], b_val = a[j];
        if (a_val > b_val) {
            for (int x = max(b_val / 2, a_val / 3) + 1; x <= a_val / 2; x++) {
                a[i] = x;
                a[cur++] = a_val - x;
                dfs();
                // 恢复现场
                a[i] = a_val;
                cur--;
            }
        } else {
            return;
        }
    }
}

int main() {
    cin >> n;
    a[0] = n; // 初始化只有一堆
    dfs();
    cout << m << " " << d << endl;
    return 0;
}