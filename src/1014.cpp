#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int T, n, a[N];
long long ans;

int main() {
    a[0] = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        ans = a[1];
        int i = 1, j = 0;
        long long sum = 0;
        while (j < n) {
            sum += a[++j];
            ans = max(ans, sum);
            if (sum < 0) {
                i = j + 1;
                sum = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}