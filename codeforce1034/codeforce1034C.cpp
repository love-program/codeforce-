#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Ԥ����ǰ׺��Сֵ�ͺ�׺���ֵ
        vector<int> prefix_min(n);
        prefix_min[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix_min[i] = min(prefix_min[i-1], a[i]);
        }
        
        vector<int> suffix_max(n);
        suffix_max[n-1] = a[n-1];
        for (int i = n-2; i >= 0; --i) {
            suffix_max[i] = max(suffix_max[i+1], a[i]);
        }
        
        // ������
        string ans(n, '0');
        for (int i = 0; i < n; ++i) {
            // �����ǰԪ���������Сֵ���Ҳ����ֵ������Ϊ '1'
            if (a[i] == prefix_min[i] || a[i] == suffix_max[i]) {
                ans[i] = '1';
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
