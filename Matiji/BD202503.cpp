// //暴力超时
// #include<bits/stdc++.h>
// using namespace std;
// vector<int> ans;
// vector<int> nums;
// vector<bool> visited;
// int n;
// int mex = 0;
// int res = 0;
// int g = 0;
// // Version 1
// int gcd(int a, int b) {
//     if (b == 0) return a;
//     return gcd(b, a % b);
// }

// void solve()
// {
//     mex = 0;
//     g = 0;
//     vector<int>current = ans;
//     for (int i = 0; i < current.size(); i++)
//     {
//         if (current[i] == mex)
//         {
//             mex++;
//         }
//         g = gcd(current[i], g);
//     }
//     int cur = g ^ mex;
//     if (cur > res)
//     {
//         res = cur;
//     }
// }
// void dfs(int step, int k)
// {
//     if (step == k)
//     {
//         solve();
//         return;
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (!visited[i])
//         {
//             visited[i] = true;
//             ans.push_back(nums[i]);
//             dfs(step + 1, k);
//             visited[i] = false;
//             ans.pop_back();
//         }
//     }

// }
// int main()
// {
//     cin >> n;
//     nums.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> nums[i];
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         visited.resize(n, false);
//         ans.clear();
//         dfs(0, i);
//         cout << res << " ";
//         res = 0;
//     }
// }