#include<bits/stdc++.h>
using namespace std;

const int N = 25;

int T, n, m;
long long a[N], sum[N], f[N][N][N];
// m 个乘号

int main() {
    FILE *fp = fopen("src\\input", "r");
    sum[0] = 0;
    // scanf("%d", &T);
    fscanf(fp, "%d", &T);
    while (T--) {
        // scanf("%d%d", &n, &m);
        fscanf(fp, "%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            // scanf("%lld", &a[i]);
            fscanf(fp, "%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        memset(f, 0x00, sizeof(f));
        for (int l = 1; l <= n; l++) {
            for (int r = 1; r <= n; r++) {
                f[l][r][0] = sum[r] - sum[l - 1];
            }
        }
        for (int len = 2)

        // f[1][1] = a[1];
        // for (int i = 2; i <= n; i++) {
        //     f[i][0] = sum[i];
        //     int jMax = min(i - 1, m);
        //     for (int j = 1; j <= jMax; j++) {
        //         int kMin = max(1, j);
        //         for (int k = i - 1; k; k--) {
        //             f[i][j] = max(f[i][j], f[k][j - 1] * (sum[i] - sum[k]));
        //         }
        //     }
        // }
        // printf("%lld\n", f[n][m]);
    }
    fclose(fp);
    return 0;
}