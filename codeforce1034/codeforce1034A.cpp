#include <iostream>
#include <vector>
using namespace std;

// ����0��n-1��ģ4��r�����ĸ���
int count_mod(int n, int r) {
    return (n + 4 - r - 1) / 4; // �ȼ��� (n-1 - r)/4 + 1
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // �����������������
        int cnt0 = count_mod(n, 0); // ��0�����ĸ���
        int cnt1 = count_mod(n, 1); // ��1�����ĸ���
        int cnt2 = count_mod(n, 2); // ��2�����ĸ���
        int cnt3 = count_mod(n, 3); // ��3�����ĸ���
        
        // ����ʤ�����
        // ���1: ��0����3����������ɶԣ���1����2����������ɶ�
        int pairs03 = min(cnt0, cnt3);
        int pairs12 = min(cnt1, cnt2);
        int total_pairs = pairs03 + pairs12;
        
        // �ܶ���*2��ʾ���Խ��е�������ÿ������2������
        if (total_pairs * 2 < n) {
            // �����޷���Ե���������˿������ѡ��Щ���ñ����޷���Ӧ
            cout << "Alice" << endl;
        } else {
            // ������������ԣ����ܶ�������ż��
            if (total_pairs % 2 == 1) {
                // �����֣�����˿���ж������һ���ɰ���˿���
                cout << "Alice" << endl;
            } else {
                // ż���֣�����������һ�֣�����˿�޷��ж�
                cout << "Bob" << endl;
            }
        }
    }
    return 0;
}
