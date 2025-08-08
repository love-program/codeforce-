#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n + 1);
    set<int> num;
    int max_num = 0;
    int max_num2;
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num.insert(a[i]);
        if (a[i] == a[i - 1])
        {
            cur++;
            max_num = max(max_num, cur);
        }
        else {
            cur = 1;
        }
    }
    //  cout<<max_num<<endl;
    max_num2 = max_num;
    int p = num.size();
    for (int i = 0; i < p; i++)
    {
        vector<int> k = a;
        int chose = *num.begin();
        num.erase(num.begin());
        int cur = 1;
        int last = 0;
        for (int j = 1; j <= n; j++)
        {

            if (k[j] == chose)
            {
                if (k[j] != k[j - 1])
                {
                    last = k[j - 1];
                }
                continue;
            }
            if (k[j] == k[j - 1] || k[j] == last)
            {
                cur++;
                max_num2 = max(max_num2, cur);
                if (k[j] == last)
                {
                    last = 0;
                }
            }
            else
            {
                cur = 1;
            }
        }
    }
    cout << max_num2 - max_num << endl;
}