#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int hikes = 0;
        for (int i = 0; i <= n - k; ) {
            bool valid = true;
            for (int j = 0; j < k; j++) {
                if (a[i + j] == 1) {
                    valid = false;
                    i = i + j + 1;
                    break;
                }
            }
            if (valid) {
                hikes++;
                i += k + 1;
            }
        }
        cout << hikes << endl;
    }
    return 0;
}    
