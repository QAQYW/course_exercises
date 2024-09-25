#include <bits/stdc++.h>
using namespace std;

int const N = 1e4 + 5;

int T, n, dp[N];
struct Activity {
    int s, f, v;
} act[N]

bool cmp(Activity x, Activity y) {
    return x.f < y.f;
}

void solve() {
    int j = 1, m = act[n].f - 1;
    memset(dp, 0x00, sizeof(dp));
    for (int i = 1; i <= m; i++) {

    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> act[i].s >> act[i].f >> act[i].v;
        sort(act + 1, act + n + 1, cmp);
        solve();
    }
    return 0;
}