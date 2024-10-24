#include <bits/stdc++.h>
using namespace std;

int const N = 1e4 + 5;

int T, n;
struct Point {
    int color, pos;
} stk[N];
int tp, ans;


int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        tp = 0;
        ans = 0;
        n <<= 1;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            if (tp == 0 || x == stk[tp].color) {
                stk[++tp].color = x;
                stk[tp].pos = i;
            } else {
                ans += i - stk[tp--].pos;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}