#include<bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;

int T, n, a[N], tmp[N];

int mergeSort(int l, int r) {
    if (l == r) return 0;
    if (l + 1 == r) {
        if (a[l] > a[r]) {
            swap(a[l], a[r]);
            return 1;
        }
        return 0;
    }
    int mid = (l + r) >> 1;
    int res = mergeSort(l, mid) + mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[j] < a[i]) {
            tmp[k++] = a[j++];
            res += mid - i + 1;
        } else {
            tmp[k++] = a[i++];
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = tmp[i];
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        printf("%d\n", mergeSort(1, n));
    }
    return 0;
}