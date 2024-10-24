#include <bits/stdc++.h>
using namespace std;

int const N = 1e3 + 5;

int T, n, m, tar, a[N][N];

int main() {
    cin >> T;
    while (T--) {
        cin >> m >> n >> tar;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                // ? 读入的时候判断不就好了
            }
        }
        bool flag = false;
        int x = m, y = 1;
        while (true) {
            if (a[x][y] == tar) {
                flag = true;
                break;
            }
            if (a[x][y] < tar) {
                if (y == n) break;
                ++y;
            } else {
                if (x == 1) break;
                --x;
            }
        }
        if (flag) puts("true");
        else puts("false");
    }
    return 0;
}