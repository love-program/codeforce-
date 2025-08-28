// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int k;
//     cin >> k;
//     while (k--)
//     {
//         int n;
//         cin >> n;
//         int a, b;
//         cin >> a >> b;
//         if (a == b)
//         {
//             if (a % 2 == n % 2)
//             {
//                 cout << "YES" << endl;
//             }
//             else
//             {
//                 if (a <= n / 2)
//                 {
//                     cout << "YES" << endl;
//                 }
//                 else
//                 {
//                     cout << "NO" << endl;
//                 }
//             }
//         }
//         else
//         {
//             if (a > b)
//             {
//                 if (a % 2 != b % 2)
//                 {
//                     cout << "NO" << endl;
//                 }
//                 else{
//                     if(a%2!=n%2||b%2!=n%2){
//                         cout<<"NO"<<endl;
//                     }
//                     else
//                     {
//                         cout << "YES" << endl;
//                     }
//                 }
//             }
//             if(a<b)
//             {
//                 if(b%2!=n%2)
//                 {
//                     cout<<"NO"<<endl;
//                 }
//                 else
//                 {
//                     cout<<"YES"<<endl;
//                 }
//             }
//         }
//     }
// }
#include <iostream>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    if (n % 2 != b % 2) {
        // 蓝色部分无法对称，无解
        cout << "NO" << endl;
    } else {
        if (a > b && n % 2 != a % 2) {
            // a > b 时，红色部分也必须对称，但n, a奇偶性不同
            cout << "NO" << endl;
        } else {
            // 其他情况都有解：
            // 1. a <= b (只要 n, b 奇偶性相同即可)
            // 2. a > b 且 n, a, b 奇偶性都相同
            cout << "YES" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}