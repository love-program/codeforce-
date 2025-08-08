#include<bits/stdc++.h>
using namespace std;
vector<long long> p, s, sum;

int main()
{
    int n;
    long long m; 
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        long long pi, si; 
        cin >> pi >> si;
        p.push_back(pi);
        s.push_back(si);
        sum.push_back(pi + si);
    }

    int max_supplied_count = 0; 

    for(int i = 0; i < n; i++)
    {
        sum[i] -= p[i]/2;

        vector<long long> temp_costs = sum;
        sort(temp_costs.begin(), temp_costs.end());

        long long current_budget = m;
        int current_count = 0;
        for(int j = 0; j < n; j++) {
        
            if (current_budget >= temp_costs[j]) {
                current_budget -= temp_costs[j]; 
                current_count++;                 
            } else {
                break;
            }
        }
        
        if (current_count > max_supplied_count) {
            max_supplied_count = current_count;
        }

        
        sum[i] += p[i]/2; 
    }

    cout << max_supplied_count << endl;

    return 0; 
}
// #include<bits/stdc++.h> // 包含了所有标准库头文件
// using namespace std;
// int main()
// {
//     int n,m;
//     int ans=0;
//     cin>>n>>m;
//     vector<int>p(n+1);
//     vector<int>s(n+1);
//     vector<int>sum(n+1);
//     vector<int>bonus(n+1);
//     for(int i=1;i<=n;i++)
//     {
//         cin>>p[i];
//         cin>>s[i];
//         sum[i]=p[i]+s[i];
//         bonus[i]=floor(p[i]/2);
//     }
//     int current=m;
//     int k=0;
//     int minus=0;
//     while(current>0&&k<=n)
//     {
//         k++;
//         current-=sum[k];
//         minus=max(minus,bonus[k]);
//     }
//     ans=k;
//     current+=sum[k];
//     cout<<ans+1<<endl;
    
//     // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//     // for(int i=1;i<=n;i++)
//     // {
//     //     for(int j=0;j<=m;j++)
//     //     {
//     //         dp[i][j]=dp[i-1][j];
//     //         if(j>=p[i]+s[i])
//     //         {
//     //             dp[i][j]=max(dp[i][j],dp[i-1][j-p[i]]+s[i]);
//     //         }
//     //     }
//     // }
// }