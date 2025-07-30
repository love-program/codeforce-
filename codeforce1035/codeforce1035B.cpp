#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int px, py, qx, qy;
        cin >> px >> qx >> py >> qy;
        double D = sqrt(pow(px - py, 2) + pow(qx - qy, 2));
        double sum = 0, max_a = 0;
        for (int i = 0; i < n; i++) {
            double a;
            cin >> a;
            sum += a;
            if (a > max_a) max_a = a;
        }
        if (max_a <= sum - max_a + D && D <= sum) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
