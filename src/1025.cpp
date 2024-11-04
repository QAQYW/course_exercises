#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

int T, n, a[N], f[N], len;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        f[len = 1] = a[1];
        for (int i = 2; i <= n; i++) {
            if (a[i] >= f[len]) {
                f[++len] = a[i];
            } else {
                int l = 1, r = len, mid, pos;
                while (l <= r) {
                    mid = (l + r) >> 1;
                    if (a[i] >= f[mid]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                        pos = mid;
                    }
                }
                f[pos] = a[i];
            }
        }
        printf("%d\n", len);
    }
    return 0;
}