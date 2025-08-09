//本题的的关键在于，当遍历到某个位置不匹配时，需要将ans清0,；
//为什么呢？是因为，此时已经是不匹配的了，前面修改的任何可能都将作废，重新开始，类似于“（（（（））））（（（）”其中2,3,4不可以修改
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k=0;
    int ans=0;
    string input;
    cin>>input;

    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(')
            k++;
    }
    if(k==input.size()/2)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else if(input[0]==')'||input[input.size()-1]=='(')
    {
        cout<<"1"<<endl;
        return 0;
    }
    else if(k>input.size()/2)
    {
        int m=0;
        for(int i=0;i<input.size();i++)
        {
            if(input[i]=='(')
            {
                m++;
                ans++;
                if(m<2)
                ans=0;
               
            }
            else
            {
                m--;
                if(m<2)
                ans=0;
            }
        }
    }
    else
    {
        int m=0;
        reverse(input.begin(),input.end());
        for(int i=0;i<input.size();i++)
        {
            if(input[i]==')')
            {
                m++;
                ans++;
                if(m<2)
                ans=0;
               
            }
            else
            {
                m--;
                if(m<2)
                ans=0;
            }
        }
    }
    cout<<ans<<endl;
}