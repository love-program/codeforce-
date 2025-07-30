#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Casino {
    int l, r, real;
};

bool compareByReal(const Casino& a, const Casino& b) {
    return a.real < b.real;
}

bool compareByL(const Casino& a, const Casino& b) {
    return a.l > b.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Casino> casinos(n);
        for (int i = 0; i < n; i++) {
            cin >> casinos[i].l >> casinos[i].r >> casinos[i].real;
        }

        vector<Casino> gain, loss;
        for (int i = 0; i < n; i++) {
            if (casinos[i].real >= casinos[i].l) {
                gain.push_back(casinos[i]);
            } else {
                loss.push_back(casinos[i]);
            }
        }

        // ��reali���������Ͷĳ�
        sort(gain.begin(), gain.end(), compareByReal);

        // ��li������ʧ�Ͷĳ�
        sort(loss.begin(), loss.end(), compareByL);

        int current = k;
        // ���������Ͷĳ�
        for (int i = 0; i < gain.size(); i++) {
            if (current >= gain[i].l && current <= gain[i].r) {
                current = max(current, gain[i].real);
            }
        }

        // ������ʧ�Ͷĳ�
        for (int i = 0; i < loss.size(); i++) {
            if (current >= loss[i].l && current <= loss[i].r) {
                current = loss[i].real;
            }
        }

        cout << current << endl;
    }
    return 0;
}
