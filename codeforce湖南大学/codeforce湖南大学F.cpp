#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << "Yes" << endl;
            continue;
        }
        
        if (a[0] % 2 == 0) {
            cout << "No" << endl;
        }
		 else 
		 {
            bool has_odd = false;
            for (int i = 1; i < n - 1; ++i) {
                if (a[i] % 2 == 1) {
                    has_odd = true;
                    break;
                }
            }
            cout << (has_odd ? "No" : "Yes") << endl;
        }
    }
    
    return 0;
}
