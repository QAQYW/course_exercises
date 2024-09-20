#include <bits/stdc++.h>
using namespace std;

int T, n, a[1005];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}