// 期望字符匹配法,先用期望字符栈匹配所需字符串的字符，如果是，则当前的S位置未来不再用了，进入下一个S位置；不然，在当前S位置进行对应操作
#include<bits/stdc++.h>
using namespace std;
struct opt{
    int w;
    int pos;
    opt(int a,int b)
    {
        this->w=a;
        this->pos=b;
    }
};
int main()
{
    string input;
    cin >> input;
    int n=input.size();
    int temp = 0;
    // 增加长度为偶数的检查
    if(n % 2 != 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '0')
            temp++;
    }
    if (temp != input.size() / 2)
    {
        cout << "-1" << endl;
        return 0;
    }
    stack<int> m;
    vector<opt>ans;
    if(input[0]=='1')
    {
        opt a= opt(2,1);
        ans.push_back(a);
        m.push(0);
    }
    else{
        opt a=opt(1,1);
        ans.push_back(a);
        m.push(1);
    }
    int cur = 1;

    for (int i = 1; i < input.size(); i++)
    {
        if (!m.empty())
        {
            int k = m.top();
            if (k != input[i] - '0')
            {
                opt a=opt(2-k,cur);
                ans.push_back(a);
                m.push(k);
            }
            else
            {
                m.pop();
                cur++;
            }
        }
        else
        {
            if (input[i] == '1')
            {
                opt a = opt(2, cur);
                ans.push_back(a);
                m.push(0);
            }
            else
            {
                opt a = opt(1, cur);
                ans.push_back(a);
                m.push(1);
            }
        }
    }
    //实际上不需要，一定是匹配的
    // 关键修复：检查栈是否为空，确保所有期望字符都被匹配
    // if(!m.empty())
    // {
    //     cout << "-1" << endl;
    //     return 0;
    // }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].pos<<" "<<ans[i].w<<endl;
    }
}
// #include<bits/stdc++.h>
// using namespace std;

// struct opt{
//     int w;  // 操作类型
//     int pos; // 操作位置
//     opt(int a,int b)
//     {
//         this->w = a;
//         this->pos = b;
//     }
// };

// int main()
// {
//     string input;
//     cin >> input;
//     int n = input.size();
//     int temp = 0;
    
//     // 增加长度为偶数的检查
//     if(n % 2 != 0)
//     {
//         cout << "-1" << endl;
//         return 0;
//     }
    
//     for(int i = 0; i < input.size(); i++)
//     {
//         if(input[i] == '0')
//             temp++;
//     }
    
//     if(temp != input.size() / 2)
//     {
//         cout << "-1" << endl;
//         return 0;
//     }
    
//     stack<int> m;
//     vector<opt> ans;
    
//     // 初始化处理第一个字符
//     if(input[0] == '1')
//     {
//         opt a = opt(2, 1);  // 操作2生成1开头
//         ans.push_back(a);
//         m.push(0);  // 期望后续出现0
//     }
//     else
//     {
//         opt a = opt(1, 1);  // 操作1生成0开头
//         ans.push_back(a);
//         m.push(1);  // 期望后续出现1
//     }
    
//     int cur = 1;  // 当前操作的S位置

//     for(int i = 1; i < input.size(); i++)
//     {
//         if(!m.empty())
//         {
//             int k = m.top();
//             if(k != input[i] - '0')
//             {
//                 // 不匹配，对当前位置执行对应操作
//                 opt a = opt(2 - k, cur);  // 1对应操作1，0对应操作2
//                 ans.push_back(a);
//                 m.push(k);  // 继续期望相同字符
//             }
//             else
//             {
//                 // 匹配成功，处理下一个S
//                 m.pop();
//                 cur++;
//             }
//         }
//         else
//         {
//             // 栈为空，开始新的操作
//             if(input[i] == '1')
//             {
//                 opt a = opt(2, cur);
//                 ans.push_back(a);
//                 m.push(0);
//             }
//             else
//             {
//                 opt a = opt(1, cur);
//                 ans.push_back(a);
//                 m.push(1);
//             }
//         }
//     }
    
//     // 关键修复：检查栈是否为空，确保所有期望字符都被匹配
//     if(!m.empty())
//     {
//         cout << "-1" << endl;
//         return 0;
//     }
    
//     // 修复输出顺序：先pos后op
//     cout << ans.size() << endl;
//     for(int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i].pos << " " << ans[i].w << endl;
//     }
    
//     return 0;
// }
    

//供需关系求解发
// #include <bits/stdc++.h>
// using namespace std;
// typedef pair<int, int> PII;
// #define x first
// #define y second

// string s;
// vector<PII> ans;

// int main()
// {
//     cin >> s;

//     int l = 0, r = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '1') l++;
//         else r++;
//     }
//     if (l != r)
//     {
//         cout << -1 << endl;
//         return 0;
//     }

//     int cz = 0, co = 0; // create_zero, create_one
//     int sz = 0, so = 0; // sum_zero, sum_one;
//     int cur = 1;        // 当前操作的标识符
//     for (int i = 0; i < s.size(); i++)
//         if (s[i] == '0')
//         {
//             sz++;
//             if (sz > cz)
//             {
//                 ans.push_back({cur, 1});
//                 cz++, co++;
//             }
//             else cur++;
//         }
//         else
//         {
//             so++;
//             if (so > co)
//             {
//                 ans.push_back({cur, 2});
//                 cz++, co++;
//             }
//             else cur++;
//         }

//     cout << ans.size() << endl;
//     for (int i = 0; i < ans.size(); i++)
//         cout << ans[i].x << " " << ans[i].y << endl;

//     return 0;
// }