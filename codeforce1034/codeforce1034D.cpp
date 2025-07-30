#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                count++;
            }
        }
        
        if (count <= k) {
            cout << "Alice" << endl;
        } else if (n <= 2 * k - 1) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
    
    return 0;
}
