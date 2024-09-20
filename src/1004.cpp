#include <bits/stdc++.h>
using namespace std;

int T, n, a[1005];
int m1, m2, m3;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        m2 = (n - 1) >> 1;
        m1 = m2 >> 1;
        m3 = (m2 + 1 + n - 1) >> 1;
        sort(a, a + m1 + 1);
        sort(a + m1 + 1, a + m2 + 1);
        sort(a + m2 + 1, a + m3 + 1);
        sort(a + m3 + 1, a + n);
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        puts("");
    }
    return 0;
}