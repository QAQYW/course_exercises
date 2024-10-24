#include <bits/stdc++.h>
using namespace std;

int const N = 1e4 + 5;
double const EXPS = 1e-10;

int T, n, radius, sqrRadius;

struct Vessel {
    int x, y;
    double left, right;
    void setSegment() {
        double len = sqrt(sqrRadius - y * y);
        left = x - len;
        right = x + len;
    }
} a[N];

bool cmp(Vessel v1, Vessel v2) {
    return v1.left < v2.left;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> radius;
        sqrRadius = radius * radius;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
            a[i].setSegment();
        }
        sort(a + 1, a + n + 1, cmp);
        double l = a[1].left, r = a[1].right;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i].left - r <= EXPS) {
                l = max(l, a[i].left);
                r = min(r, a[i].right);
            } else {
                ++ans;
                l = a[i].left;
                r = a[i].right;
            }
        }
        cout << ans << endl;
    }
    return 0;
}