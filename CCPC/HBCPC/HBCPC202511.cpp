// //TLE:优化找下家思路
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,k;
//     cin>>n>>k;
//     int temp=n;
//     vector<int> p(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>p[i];
//     }
//     string input;
//     cin>>input;
//     int cur=0;
//     bool check=true;
//     for(int i=0;i<k;i++)
//     {
//         while(p[cur]==0)
//         {
//              if(check)
//             {
//                 cur++;
//                 if(cur>=n)
//                 cur-=n;
//             }
//             else
//             {
//                 cur--;
//                 if(cur<0)
//                 cur+=n;
//             }
//         }
//         p[cur]--;
//         if(input[i]=='S')
//         {
//             if(check)
//             {
//                 cur++;
//                 if(cur>=n)
//                 cur-=n;
//             }
//             else
//             {
//                 cur--;
//                 if(cur<0)
//                 cur+=n;
//             }
//             while(p[cur]==0)
//             {
//                  if(check)
//                 {
//                     cur++;
//                     if(cur>=n)
//                     cur-=n;
//                 }
//                 else
//                 {
//                     cur--;
//                     if(cur<0)
//                     cur+=n;
//                 }
//             }
//         }
//         else if(input[i]=='R')
//         {
//             check=!check;
//         }
//         else if(input[i]=='D')
//         {
//             if(check)
//             {
//                 cur++;
//                 if(cur>=n)
//                 cur-=n;
//             }
//             else
//             {
//                 cur--;
//                 if(cur<0)
//                 cur+=n;
//             }
//             while(p[cur]==0)
//             {
//                  if(check)
//                 {
//                     cur++;
//                     if(cur>=n)
//                     cur-=n;
//                 }
//                 else
//                 {
//                     cur--;
//                     if(cur<0)
//                     cur+=n;
//                 }
//             }
//             p[cur]+=2;
//         }
//         if(check)
//         {
//             cur++;
//             if(cur>=n)
//             cur-=n;
//         }
//         else
//         {
//             cur--;
//             if(cur<0)
//             cur+=n;
//         }
//     }
//     for(int i=0;i<temp;i++)
//     {
//         cout<<p[i]<<endl;
//     }
// }
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    map<int,int> num;
    
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    string input;
    int cur=1;
    bool check=true;
    for(int i=0;i<k;i++)
    {
        num[cur]--;
        if(num[cur]==0)
        {
            num.erase(cur);
             if(check)
            {
                cur++;
                if(cur>=num.size())
                cur-=num.size();
            }
            else
            {
                cur--;
                 if(cur<0)
                 cur+=num.size();
            }
        }
         if(input[i]=='S')
        {
            if(check)
            {
                cur++;
                if(cur>=num.size())
                cur-=num.size();
            }
            else
            {
                cur--;
                if(cur<0)
                cur+=num.size();
            }
        }
        else if(input[i]=='R')
        {
            check=!check;
        }
        else if(input[i]=='D')
        {
            if(check)
            {
                cur++;
                if(cur>=num.size())
                cur-=num.size();
            }
            else
            {
                cur--;
                if(cur<0)
                cur+=num.size();
            }
            num[cur]+=2;
        }
        if(check)
        {
            cur++;
            if(cur>=num.size())
            cur-=num.size();
        }
        else
        {
            cur--;
            if(cur<0)
            cur+=num.size();
        }
    }
    for(int i=0;i<n;i++)
    {
        if(num.count(i))
        {
            cout<<num[i]<<endl;;
        }
        else{
            cout<<0<<endl;
        }
    }
}