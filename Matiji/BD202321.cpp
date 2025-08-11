//points滚动数组统计上一次的位置
//set用于收集已经计算过的数字，防止重复计算
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int ans=0;
    set<int> num;
    vector<int>points(1e6);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        if(num.count(m))
        {
            continue;
        }
        if(points[m]==0)
        {
            points[m]=i;
        }
        else
        {
            if(i-points[m]<=k)
            {
                ans=ans^m;
                num.insert(m);
            }
            else 
            {
                points[m]=i;
            }
        }
    }
    cout<<ans<<endl;
}