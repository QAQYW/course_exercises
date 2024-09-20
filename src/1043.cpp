#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int K = 105;
int f[N][K];

int dp(int n, int k) {
    if (f[n][k]) return f[n][k];
    if (k == 1) return n;
    f[n][k] = n;
    for (int i = 2; i <= n; i++)
        f[n][k] = min(f[n][k], max(dp(i - 1, k - 1), dp(n - i, k)) + 1);
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