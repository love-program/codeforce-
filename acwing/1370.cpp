// #include<bits/stdc++.h>
// using namespace std;
// int k;
// vector<char> s(k,'0');

// bool getans(int k)
// {
//     int ans = 1;
//     cout<<1<<endl;
//     for(int i=1;i<k;i++)
//     {
//         if(s[i]=='+')
//         {
//             ans+=i+1;
//         }
//         else if(s[i]=='-')
//         {
//             ans-=i+1;
//         }
//         else if(s[i]==' ')
//         {
//             ans+=i*10+1;
//         }
//     }
//     if(ans==0)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }

// bool dfs(int n)
// {
//     if(n>k)
//     {
//         if(getans(n))
//         {
//             for(int i=1;i<k;i++)
//             {
//                 cout<<i;
//                 cout<<s[i];
//             }
//             cout<<k;
//             cout<<endl;
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     s[n] = '+';
//     if(dfs(n+1)) return true;
//     s[n] = '-';
//     if(dfs(n+1)) return true;
//     s[n] = ' ';
//     if(dfs(n+1)) return true;
//     return false;
// }


// int main()
// {
//     cin >> k;
//     dfs(1);
// }

#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> symbols; // 存储符号（+、-、空格）
vector<string> results; // 存储满足条件的表达式

// 计算表达式值并判断是否为 0
bool evaluate() {
    vector<long long> numbers; // 使用 long long 防止溢出
    vector<char> ops; // 存储操作符
    string num = "1"; // 从第一个数字开始

    for (int i = 0; i < N - 1; i++) {
        if (symbols[i] == ' ') {
            num += to_string(i + 2); // 合并数字
        } else {
            numbers.push_back(stoll(num)); // 转换为数字
            num = to_string(i + 2); // 开始新数字
            ops.push_back(symbols[i]); // 记录操作符
        }
    }
    numbers.push_back(stoll(num)); // 最后一个数字

    // 计算结果
    long long result = numbers[0];
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == '+') {
            result += numbers[i + 1];
        } else {
            result -= numbers[i + 1];
        }
    }
    return result == 0; // 返回是否为 0
}

// 构造表达式字符串
string build_expression() {
    string expr = "1";
    for (int i = 0; i < N - 1; i++) {
        expr += symbols[i];
        expr += to_string(i + 2);
    }
    return expr;
}

// DFS 搜索所有可能的符号组合
void dfs(int pos) {
    if (pos == N - 1) { // 所有符号都填充完毕
        if (evaluate()) { // 如果表达式值为 0
            results.push_back(build_expression());
        }
        return;
    }

    // 按 ASCII 顺序尝试符号：空格、+、-
    symbols[pos] = ' ';
    dfs(pos + 1);
    symbols[pos] = '+';
    dfs(pos + 1);
    symbols[pos] = '-';
    dfs(pos + 1);
}

int main() {
    cin >> N;
    symbols.resize(N - 1); // 符号数量为 N-1
    dfs(0);

    // 按 ASCII 顺序输出
    sort(results.begin(), results.end());
    for (const auto& expr : results) {
        cout << expr << endl;
    }

    return 0;
}