#include <iostream>
#include <vector>
using namespace std;

// 计算0到n-1中模4余r的数的个数
int count_mod(int n, int r) {
    return (n + 4 - r - 1) / 4; // 等价于 (n-1 - r)/4 + 1
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // 计算各类余数的数量
        int cnt0 = count_mod(n, 0); // 余0的数的个数
        int cnt1 = count_mod(n, 1); // 余1的数的个数
        int cnt2 = count_mod(n, 2); // 余2的数的个数
        int cnt3 = count_mod(n, 3); // 余3的数的个数
        
        // 分析胜负情况
        // 情况1: 余0和余3的数可以组成对，余1和余2的数可以组成对
        int pairs03 = min(cnt0, cnt3);
        int pairs12 = min(cnt1, cnt2);
        int total_pairs = pairs03 + pairs12;
        
        // 总对数*2表示可以进行的轮数（每轮消耗2个数）
        if (total_pairs * 2 < n) {
            // 存在无法配对的数，爱丽丝可以先选这些数让鲍勃无法回应
            cout << "Alice" << endl;
        } else {
            // 所有数都能配对，看总对数的奇偶性
            if (total_pairs % 2 == 1) {
                // 奇数轮，爱丽丝先行动，最后一轮由爱丽丝完成
                cout << "Alice" << endl;
            } else {
                // 偶数轮，鲍勃完成最后一轮，爱丽丝无法行动
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}
