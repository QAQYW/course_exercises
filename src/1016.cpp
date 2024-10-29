#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int T, n, sum, a[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &sum);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int i = 1, j = n;
        while (i < j) {
            if (a[i] + a[j] == sum) break;
            if (a[i] + a[j] > sum) --j;
            else ++i;
        }
        if (i < j) puts("yes");
        else puts("no");
    }
    return 0;
}