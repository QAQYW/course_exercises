#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int T, n;
long long s[N], t[N], f[N][N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld%lld", &s[i], &t[i]);
            f[i][i] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1, r = len; r <= n; l++, r++) {
                f[l][r] = f[l][l] + f[l + 1][r] + s[l] * t[l] * t[r];
                for (int mid = l + 1; mid < r; mid++) {
                    f[l][r] = min(f[l][r], f[l][mid] + f[mid + 1][r] + s[l] * t[mid] * t[r]);
                }
            }
        }
        printf("%lld\n", f[1][n]);
    }
    return 0;
}