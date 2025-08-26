#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> count;  // 记录每个齿数出现的次数
        bool possible = false;
        
        for (int i = 0; i < n; ++i) {
            int teeth;
            cin >> teeth;
            count[teeth]++;
            // 如果发现某个齿数出现至少两次，说明可以组成合格装置
            if (count[teeth] >= 2) {
                possible = true;
            }
        }
        
        cout << (possible ? "YES" : "NO") << endl;
    }
    
    return 0;
}
