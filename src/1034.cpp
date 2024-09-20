#include <bits/stdc++.h>
using namespace std;

const int N = 50000 + 5;

int T, n;
int head[N], cnt(0), nxt[N << 1], to[N << 1];
int f[N][2];

void add_edge(int u, int v) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}

void dp(int x, int fa) {
    int m0 = 0, m1 = 0;
    for (int i = head[x], y; ~i; i=nxt[i]) {
        if ((y = to[i]) == fa) continue;
        dp(y, x);
        m0 += f[y][0];
        m1 += max(f[y][0], f[y][1]);
    }
    f[x][0] = m1;
    f[x][1] = m0 + 1;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 1) {
            puts("1");
            continue;
        }
        cnt = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            add_edge(u, v);
            add_edge(v, u);
        }
        memset(f, 0x00, sizeof(f));
        dp(1, 0);
        cout << max(f[1][0], f[1][1]) << endl;
    }
    return 0;
}