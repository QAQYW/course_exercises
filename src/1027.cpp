#include <bits/stdc++.h>
using namespace std;

int const N = 1e4 + 5;

int T, n, dp[N];
struct Activity {
    int s, f, v;
} act[N];

bool cmp(Activity x, Activity y) {
    return x.f < y.f;
}

void solve() {
    memset(dp, 0x00, sizeof(dp));
    act[0].s = act[0].f = act[0].v = 0;
    for (int i = 1, j, l, r, mid; i <= n; i++) {
        dp[i] = dp[i - 1];
        l = 0;
        r = i - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (act[mid].f <= act[i].s) {
                l = mid + 1;
                j = mid;
            } else {
                r = mid - 1;
            }
        }
        dp[i] = max(dp[i], dp[j] + act[i].v);
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
        cout << dp[n] << endl;
    }
    return 0;
}