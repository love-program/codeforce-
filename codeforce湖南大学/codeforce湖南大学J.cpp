#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    cout << fixed << setprecision(15);
    
    const int MAX_N = 1e5;
    vector<double> harmonic(MAX_N + 1, 0.0);
    
    for (int n = 1; n <= MAX_N; n++) {
        harmonic[n] = harmonic[n - 1] + 1.0 / n;
    }
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << harmonic[n] << "\n";
    }
    
    return 0;
}
