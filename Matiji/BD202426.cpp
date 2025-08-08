#include <bits/stdc++.h>
using namespace std;
vector<int> ans(1000000);
int main()
{
    string s = "10101";
    string input;
    cin >> input;
    int max = input.size() + 10;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = input.size() - 1; j >= 0; j--)
        {
            if (s[i] == '0')
            {
                break;
            }
            int cur = i + (input.size()-1-j);
            ans[cur] += input[j] - '0';
            if (ans[cur] >= 2)
            {
                ans[cur] -= 2;
                ans[cur + 1]++;
            }
        }
    }
    bool flag = false;
    for (int i = max; i >= 0; i--)
    {
        if (ans[i] == 0 && flag == false)
        {
            continue;
        }
        flag = true;
        cout << ans[i];
    }
}