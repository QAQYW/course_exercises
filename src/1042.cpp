#include <bits/stdc++.h>
using namespace std;

const int N = 400;

int T;
int n, days[N], costs[3]; // 1, 7, 30
int during[3] = {1, 7, 30}, to[3];
int f[N];

void solve() {
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    to[1] = to[2] = 1;
    for (int i = 1; i <= n; i++) {
        // 单日
        f[i] = min(f[i], f[i - 1] + costs[0]);
        // 多日
        for (int j = 1; j <= 2; j++) {
            while (to[j] + 1 <= n && days[to[j] + 1] - days[i] < during[j]) ++to[j];
            f[to[j]] = min(f[to[j]], f[i - 1] + costs[j]);
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> days[i];
        for (int i = 0; i < 3; i++) cin >> costs[i];
        solve();
        cout << f[n] << "\n";
    }
    return 0;
}