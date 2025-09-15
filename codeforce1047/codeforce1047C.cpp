#include <iostream>
#include <algorithm> // 用于 std::max

void solve() {
    long long a, b;
    std::cin >> a >> b;

    bool a_is_odd = (a % 2 != 0);
    bool b_is_odd = (b % 2 != 0);

    if (a_is_odd && b_is_odd) {
        // 情况 1: a 奇, b 奇
        std::cout << a * b + 1 << std::endl;
    } else if (!a_is_odd && !b_is_odd) {
        // 情况 2: a 偶, b 偶
        std::cout << std::max(a + b, a * b / 2 + 2) << std::endl;
    } else if (!a_is_odd && b_is_odd) {
        // 情况 3: a 偶, b 奇
        std::cout << -1 << std::endl;
    } else { // a_is_odd && !b_is_odd
        // 情况 4: a 奇, b 偶
        if (b % 4 != 0) {
            std::cout << -1 << std::endl;
        } else {
            // b 是 4 的倍数
            long long val1 = a * 2 + b / 2;
            long long val2 = a * (b / 2) + 2;
            std::cout << std::max(val1, val2) << std::endl;
        }
    }
}

int main() {
    // 加速 I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int k;cin>>k;
//     while(k--)
//     {
//         long long a,b;
//         cin>>a>>b;
//        if(a%2==0&&b%2==1)
//             cout<<"-1"<<endl;
//         else
//         {
//            long long m=1;
//            while(m<=b)
//            {
//                if(b%m==0&&(b/(b/m)+a*(b/m))%2==0)
//                {
//                    cout<<(b/(b/m)+a*(b/m))<<endl;
//                    break;
//                }
//                m++;
//            }
//            if(m>b)
//                cout<<"-1"<<endl;
//         }
//     }
//     return 0;
// }