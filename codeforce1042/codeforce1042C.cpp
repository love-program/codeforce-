//map+迭代器（王牌组合）
//修改后AC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n,k;
        cin>>n>>k;
        vector<bool> c(n,false);
        map<int,int>mpa;
        map<int,int>mpb;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            mpa[a%k]++;
        }
        for(int i=0;i<n;i++)
        {
            int b;
            scanf("%d",&b);
            mpa[b%k]--;
        }
        bool check=true;
          for(auto pair : mpa) {
            int rem = pair.first;   
            int diff = pair.second; 

            if (diff == 0) {
                continue;
            }
            
            
            int partner_rem = k - rem;

            // 特殊情况：如果一个数是 k 的一半（例如 k=10, rem=5），它的伙伴就是它自己
            // 这种情况下，它的差额必须是0
            if (rem == partner_rem) {
                if (diff != 0) {
                    check = false;
                    break;
                }
            }
            
            else if (mpa[rem] + mpa[partner_rem] != 0) {
                check = false;
                break;
            }
        }
        if(check)
        {
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
        // bool check=true;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(c[j]==true)
        //         {   
        //             continue;
        //         }
        //         if(b[i]%k==a[j]%k||b[i]%k==(k-a[j]%k))
        //         {
        //             c[j]=true;
        //             check=true;
        //             break;
        //         }
        //         else
        //         {
        //             check=false;
        //         }
        //     }
        //     if(!check)
        //     {
        //         cout<<"No"<<endl;
        //         break;
        //     }
        // }
        // if(check)
        // {
        //     cout<<"Yes"<<endl;
        // }
    }
}