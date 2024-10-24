#include <bits/stdc++.h>
using namespace std;

int const N = 1e5 + 5;

int T, n;
long long cost[N], demand[N], opt, tot;

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        opt = 1;
        tot = 0;
        for (int i = 1; i <= n; i++) cin >> cost[i];
        for (int i = 1; i <= n; i++) cin >> demand[i];
        for (int i = 1; i <= n; i++) {
            if (cost[i] < cost[opt] + i - opt) opt = i;
            tot += demand[i] * (cost[opt] + i - opt);
        }
        cout << tot << endl;
    }
    return 0;
}