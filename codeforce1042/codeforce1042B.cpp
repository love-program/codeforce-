#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        if(n%2==0)
        {
            for(int i=1;i<=n-1;i++)
            {
                if(i%2==1)
                {
                    cout<<-1<<" ";
                }
                else
                {
                    cout<<3<<" ";
                }
            }
            cout<<2<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(i%2==1)
                {
                    cout<<-1<<" ";
                }
                else
                {
                    cout<<3<<" ";
                }
            }
            cout<<endl;
        }
    }
}