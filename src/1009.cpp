#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int T, n, a[N];
int tp, stk[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        tp = 0;
        memset(stk, 0x00, sizeof(stk));
        for (int i = 1, j; i <= n; i++) {
            if (tp == 0 || a[i] <= a[stk[tp - 1]]) {
                stk[tp++] = i;
            } else {
                j = tp;
                while (j > 0 && a[stk[j - 1]] < a[i]) --j;
                stk[j] = i;
            }
        }
        printf("%d\n", tp);
    }
    return 0;
}