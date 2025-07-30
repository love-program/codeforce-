#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> a(n);
    int low = 0, high = n - 1;

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0') {
            a[i] = low++; 
        } else {
            a[i] = high--; 
        }
    }
    
    // �������һ��λ�ã�����s[n-1]��ֵѡ����ʵ���
    if (s[n-1] == '0') {
        // ��Ҫa[n-1] < a[0]�����Գ���ʹ��low
        if (low < a[0]) {
            a[n-1] = low;
        } else {
            // �޷���������
            cout << -1 << endl;
            return 0;
        }
    } else {
        // ��Ҫa[n-1] > a[0]�����Գ���ʹ��high
        if (high > a[0]) {
            a[n-1] = high;
        } else {
            // �޷���������
            cout << -1 << endl;
            return 0;
        }
    }

    // ������
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n-1 ? '\n' : ' ');
    }

    return 0;
}
