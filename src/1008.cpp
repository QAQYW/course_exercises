#include<bits/stdc++.h>
using namespace std;

int T;

int n, a[105], f[105], d[105],ans, t;


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ans = 1;
    t = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = t; j > 0; j--)
            if (a[i] <= a[d[j]]) {
                f[i] = f[d[j]] + 1;
                break;
            }
        t = max(t, f[i]);
        d[f[i]] = i;
        ans = max(ans, f[i]);
    }
    cout << ans << " ";
    ans = 1;
    t = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = t; j > 0; j--)
            if (a[i] > a[d[j]]) {
                f[i] = f[d[j]] + 1;
                break;
            }
        t = max(t, f[i]);
        d[f[i]] = i;
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) solve();
}