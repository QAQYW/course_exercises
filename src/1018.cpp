#include <bits/stdc++.h>
using namespace std;

const int C = 100 + 5;
const int N = 500 + 5;

int T;
int n, c, sz[N], val[N];
int f[N], vis[N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> c;
        for (int i = 1; i <= n; i++) cin >> sz[i] >> val[i];
        memset(f, 0x00, sizeof(f));
        memset(vis, 0x00, sizeof(vis));
        vis[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = c; j >= sz[i]; j--) {
                if (!vis[j - sz[i]]) continue;
                f[j] = max(f[j], f[j - sz[i]] + val[i]);
                vis[j] = 1;
            }
        }
        cout << f[c] << endl;
    }
    return 0;
}