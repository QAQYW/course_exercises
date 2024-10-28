#include <bits/stdc++.h>
using namespace std;

const int C = 100 + 5;
const int N = 500 + 5;

int T;
int n, c, sz[N], val[N];
int f[N], ans;

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> c;
        for (int i = 1; i <= n; i++) cin >> sz[i] >> val[i];
        memset(f, 0x00, sizeof(f));
        for (int i = 1; i <= n; i++) {
            for (int j = c; j >= sz[i]; j--) {
                f[j] = max(f[j], f[j - sz[i]] + val[i]);
            }
        }
        ans = 0;
        for (int j = c; j; j--) ans = max(ans, f[j]);
        cout << ans << endl;
    }
    return 0;
}