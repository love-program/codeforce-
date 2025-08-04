#include<bits/stdc++.h>
using namespace std;

void change(string &s) 
{
    bool found = false;
    for(int i=0;i<s.size();i++)
    {
        if((s[i] == '0' && s[i+1] == '0'&& s[i+2] == '0')||(s[i] == '1' && s[i+1] == '1' && s[i+2] == '1'))
        {
            s[i+1] = (s[i+1] == '0') ? '1' : '0';
            found = true;
            break;
        }
    }
    if(!found)
    {
        if((s[0] == '0' && s[1] == '0')||(s[0] == '1' && s[1] == '1'))
        {
            s[0] = (s[0] == '0') ? '1' : '0';
        }
        else if((s[s.size()-1] == '0' && s[s.size()-2] == '0')||(s[s.size()-1] == '1' && s[s.size()-2] == '1'))
        {
            s[s.size()-1] = (s[s.size()-1] == '0') ? '1' : '0';
        }
        else
        {
            for(int i=0;i<s.size()-2;i++)
            {
                if((s[i] == '0' && s[i+1] == '0')||(s[i] == '1' && s[i+1] == '1'))
                {
                    s[i+1] = (s[i+1] == '0') ? '1' : '0';
                    break;
                }
            }
        }
    }
}
bool is_good(string s)
{
    int cnt = 0;
   for(int i=0;i<s.size();i++)
   {
       if((s[i] == '0' && s[i+1] == '1')||(s[i] == '1' && s[i+1] == '0'))
       {
           cnt++;
       }
       if(cnt == 3)
       {
           return true;
       }
   }
   return false;
}
int main() {
    // Your code here
    int k;
    cin >> k;
    while(k--) 
    {
        int n;
        int res=0;
        cin >> n;
        string s;
        cin >> s;
        while(!is_good(s))
        {
            change(s);
            res++;
        }
        cout << res << endl;
    }
    return 0;
}