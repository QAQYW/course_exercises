#include <bits/stdc++.h>
using namespace std;

int T, n, a[1005], m1, m2;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        m1 = min(a[1], a[2]);
        m2 = max(a[1], a[2]);
        for (int i = 3; i <= n; i++) {
            if (a[i] < m1) {
                m2 = m1;
                m1 = a[i];
            } else if (a[i] < m2) {
                m2 = a[i];
            }
        }
        cout << m2 << endl;
    }
    return 0;
}