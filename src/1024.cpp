#include<bits/stdc++.h>
using namespace std;

// ! 未完成

const int N = 505;

int T;
int n, a[N];
double pkey[N], pgap[N], sumkey[N], sumgap[N], f[N][N];

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        sumkey[0] = sumgap[0] = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            cin >> pkey[i];
            sumkey[i] = sumkey[i - 1] + pkey[i];
        }
        for (int i = 1; i <= n + 1; i++) {
            cin >> pgap[i];
            sumgap[i] = sumgap[i - 1] + pgap[i];
        }
        for ()
    }
    return 0;
}