#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k;cin>>k;
    while(k--)
    {
        string a;
        string input;
        string check;
        string b;
        string c;
        int n;cin>>n;
        cin>>a;
        int m;cin>>m;
        cin>>input;
        cin>>check;
        for(int i=0;i<m;i++)
        {
            if(check[i]=='V')
            {
                b+=input[i];
            }
            else
            {
                c+=input[i];
            }
        }
        reverse(b.begin(), b.end());
        cout<<b<<a<<c<<endl;
    }
}