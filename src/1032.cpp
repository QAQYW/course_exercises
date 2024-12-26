#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, sum, p;
    double ans;
    cin >> T;
    while (T--) {
        cin >> n;
        sum = 100;
        for (int i = 1; i < n; i++) {
            cin >> p;
            sum += p;
        }
        ans = sum / 100.0;
        printf("%.6lf\n", ans);
    }
    return 0;
}