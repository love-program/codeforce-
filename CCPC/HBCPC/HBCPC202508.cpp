#include<bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin>>input;
    string solve;
    string check="isallyouneed";
    for(int i=0;i<input.size();i++)
    {
        if(input[i]==' ')
        {
            continue;
        }
        else if(input[i]>='A'&&input[i]<='Z')
        {
            solve.push_back(char(input[i]+('a'-'A')));
        }
        else{
            solve.push_back(input[i]);
        }
    }
    bool che=true;
    for(int i=0;i<12;i++)
    {
        if(solve[solve.size()-1-i]!=check[11-i])
        {
            che=false;
            break;
        }
    }
    if(che)
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<solve.size()-12;i++)
        {
            cout<<solve[i];
        }
    }
    else{
        cout<<"No"<<endl;
    }
}