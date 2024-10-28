#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int T, n, a[N], tmp[N];

int solve(int l, int r) {
    if (l == r) return 0;
    if (l + 1 == r) {
        if (a[l] > a[r]) {
            swap(a[l], a[r]);
            return 1;
        }
        return 0;
    }
    int mid = (l + r) >> 1;
    int res = solve(l, mid) + solve(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] < a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            res += mid - i + 1;
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = tmp[i];
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cout << solve(1, n) << endl;
    }
    return 0;
}