#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int K = 105;
int f[N][K];

int dp(int n, int k) {
    if (f[n][k]) return f[n][k];
    if (k == 1) return f[n][k] = n;
    if (n <= 2) return f[n][k] = n;
    f[n][k] = n;
    // for (int i = 2; i <= n; i++)
    //     f[n][k] = min(f[n][k], max(dp(i - 1, k - 1), dp(n - i, k)) + 1);
    int l = 2, r = n, mid, tmpl, tmpr;
    while (l < r - 1) {
        mid = (l + r) >> 1;
        tmpl = dp(mid - 1, k - 1);
        tmpr = dp(n - mid, k);
        if (tmpl == tmpr) {
            l = r = mid;
            break;
        }
        if (tmpl < tmpr) {
            l = mid;
        } else {
            r = mid;
        }
    }
    f[n][k] = min(f[n][k], max(dp(l - 1, k - 1), dp(n - l, k)) + 1);
    f[n][k] = min(f[n][k], max(dp(r - 1, k - 1), dp(n - r, k)) + 1);
    return f[n][k];
}

int main() {
    int T, n, k; // n floors, k eggs
    scanf("%d", &T);
    memset(f, 0x00, sizeof(f));
    while (T--) {
        scanf("%d%d", &k, &n);
        printf("%d\n", dp(n, k));
    }
    return 0;
}