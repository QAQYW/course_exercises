#include<bits/stdc++.h>
using namespace std;

const int N = 505;

int T;
int n, a[N];
double pkey[N], pgap[N], sumkey[N], sumgap[N], f[N][N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        sumkey[0] = sumgap[0] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            cin >> pkey[i];
            sumkey[i] = sumkey[i - 1] + pkey[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            cin >> pgap[i];
            sumgap[i] = sumgap[i - 1] + pgap[i];
        }
        for (int i = 1; i <= n; i++) f[i][i] = pkey[i] + pgap[i] + pgap[i + 1];
        for (int sz = 1; sz <= n; sz++) {
            for (int l = 1, r = sz; r <= n; l++, r++) {
                f[l][r] = 1e9 + 7;
                for (int k = l; k <= r; k++) {
                    double ansl = 0, ansr = 0;
                    if (k > l) ansl = f[l][k - 1];
                    if (k < r) ansr = f[k + 1][r];
                    f[l][r] = min(f[l][r], ansl + ansr + sumgap[r + 1] - sumgap[l - 1] + sumkey[r] - sumkey[l - 1]);
                }
            }
        }
        printf("%.6lf\n", f[1][n]);
    }
    return 0;
}