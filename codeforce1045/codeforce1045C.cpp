#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
      cin >> i;

    vector<int> b(n + 1);
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
      int mn = a[i];
      if (i >= 2)
        mn = min(mn, a[i - 1] - b[i - 2]);//跟前边剩下的比
      if (i + 1 < n)
        mn = min(mn, a[i + 1]);//跟后边的比
      b[i] = mn;
      ans += (a[i] - b[i]);
    }

    cout << ans << '\n';
  }
}