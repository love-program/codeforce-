#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(n);
    int low = 0, high = n - 1;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            a[i] = low++; 
        } else {
            a[i] = high--; 
        }
    }
    
    // 处理最后一个位置，根据s[n-1]的值选择合适的数
    if (s[n-1] == '0') {
        // 需要a[n-1] < a[0]，所以尝试使用low
        if (low < a[0]) {
            a[n-1] = low;
        } else {
            // 无法满足条件
            cout << -1 << endl;
            return 0;
        }
    } else {
        // 需要a[n-1] > a[0]，所以尝试使用high
        if (high > a[0]) {
            a[n-1] = high;
        } else {
            // 无法满足条件
            cout << -1 << endl;
            return 0;
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n-1 ? '\n' : ' ');
    }

    return 0;
}
