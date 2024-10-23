#include <bits/stdc++.h>
using namespace std;

int T, n, a[1005];
void quick_sort(int l, int r, int dep) {
    int pos = l;
    for (int i = l + 1; i <= r; i++) {
        if (a[i] < a[l]) {
            ++pos;
            swap(a[i], a[pos]);
        }
    }
    swap(a[l], a[pos]);
    if (dep == 1) {
        quick_sort(1, pos - 1, dep + 1);
        quick_sort(pos + 1, n, dep + 1);
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        quick_sort(1, n, 1);
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        puts("");
    }
    return 0;
}