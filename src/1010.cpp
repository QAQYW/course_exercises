#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 5;
int T, n, target, a[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &target);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int l = 0, r = n - 1, mid, father = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (a[mid] == target) {
                break;
            }
            father = mid;
            if (a[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (a[mid] == target) {
            printf("success, father is %d\n", a[father]);
        } else {
            printf("not found, father is %d\n", a[father]);
        }
    }
    return 0;
}