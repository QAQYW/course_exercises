#include <bits/stdc++.h>
using namespace std;

// ! 未提交
// ! 感觉后台数据有误

const int N = 105;
int T, n, a[N];
int tp, stk[N], cnt, last[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        tp = 0;
        cnt = 1;
        memset(stk, 0x00, sizeof(stk));
        memset(last, 0x00, sizeof(last));
        last[1] = a[1];
        for (int i = 1, j; i <= n; i++) {
            if (tp == 0 || a[i] <= a[stk[tp - 1]]) {
                stk[tp++] = i;
                last[1] = a[i];
                // cout << "1  ";
            } else {
                j = tp;
                while (j > 0 && a[stk[j - 1]] < a[i]) --j;
                stk[j] = i;
                if (a[i] > last[cnt]) {
                    last[++cnt] = a[i];
                    // cout << cnt << "  ";
                } else {
                    int l = 1, r = cnt, mid, pos;
                    while (l <= r) {
                        mid = (l + r) >> 1;
                        if (last[mid] == a[i]) {
                            pos = mid;
                            break;
                        }
                        if (a[i] < last[mid]) {
                            pos = mid;
                            r = mid - 1;
                        } else {
                            l = mid + 1;
                        }
                    }
                    last[pos] = a[i];
                    // cout << pos << "  ";
                }
            }
        }
        // puts("");
        printf("%d %d\n", tp, cnt);
    }
    return 0;
}