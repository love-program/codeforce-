#include <bits/stdc++.h>
#include <numeric>
using namespace std;
long long gcd(long long a,long long b)
{
    return b ==0 ? a : gcd(b , a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}
 int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<long long> b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        vector<long long> ans(n + 1);
        for (int i = n; i >= 1; i--) {
            ans[i] = lcm(a[i], b[i]);
        }
        bool ch = 1;
        if(ans[1] != a[1]) ch = 0;
        if(ans[n] != b[n]) ch = 0;
        for (int i = 2; i <= n; i++) {
            if (gcd(a[i - 1], ans[i]) != a[i]) {
                ch = 0;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (gcd(b[i + 1], ans[i]) != b[i]) {
                ch = 0;
            }
        }
        if (ch) {
            cout << "YES" << "\n";
            
        } else {
            cout << "NO" << "\n";
            
        }
        
    }
}
