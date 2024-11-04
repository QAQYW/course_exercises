#include<bits/stdc++.h>
using namespace std;

// O(n^5), n <= 20

const int N = 25;

int T, n, m;
long long a[N], sum[N], f[N][N][N];
// m 个乘号

int main() {
    sum[0] = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        memset(f, 0x00, sizeof(f));
        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                f[l][r][0] = sum[r] - sum[l - 1];
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1, r = len; r <= n; l++, r++) {
                // k = 0
                f[l][r][0] = sum[r] - sum[l - 1];
                // k >= 1
                for (int k = 1; k <= r - l && k <= m; k++) {
                    for (int mid = l; mid < r; mid++) {
                        for (int i = 0; i < k && i <= mid - l; i++) {
                            if (k - i <= r - mid) { // if (k - 1 - i <= r - mid - 1)
                                f[l][r][k] = max(f[l][r][k], f[l][mid][i] * f[mid + 1][r][k - 1 - i]);
                            }
                            if (k - i <= r - mid - 1) {
                                f[l][r][k] = max(f[l][r][k], f[l][mid][i] + f[mid + 1][r][k - i]);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n", f[1][n][m]);
    }
    return 0;
}