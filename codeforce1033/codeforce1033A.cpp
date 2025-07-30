#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        int area = l1 * b1 + l2 * b2 + l3 * b3;
        int s = sqrt(area);
        if (s * s != area) {
            cout << "NO" << endl;
            continue;
        }
        bool possible = false;
        // 检查各种可能的排列组合
        if (l1 == s && l2 == s && l3 == s && b1 + b2 + b3 == s) possible = true;
        else if (b1 == s && b2 == s && b3 == s && l1 + l2 + l3 == s) possible = true;
        else if (l1 + l2 == s && b1 == s && b2 + b3 == s) possible = true;
        else if (b1 + b2 == s && l1 == s && l2 + l3 == s) possible = true;
        else if (l1 + l3 == s && b1 == s && b2 + b3 == l1) possible = true;
        else if (b1 + l3 == s && l1 == s && l2 + l3 == b1) possible = true;
        else if (l2 + l3 == s && b2 + b3 == s && l1 == s && b1 == s) possible = true;
        else if (l1 + l2 == s && b1 == s && b2 == s && l3 == s && b3 == l1) possible = true;
        else if (l1 + l3 == s && b1 == s && b3 == s && l2 == s && b2 == l1) possible = true;
        else if (b2 + b3 == s && l2 == s && l3 == s && b1 == s && l1 == b2) possible = true;
        else if (l2 + l3 == s && b2 == s && b3 == s && l1 == s && b1 == l2) possible = true;
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}
