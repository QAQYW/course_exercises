#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int T;
int n1, n2, a1[N], a2[N];

double solve() {
    if (n1 == 0) {
        int mid = n2 >> 1;
        if (n2 & 1) return a2[mid];
        return (a2[mid] + a2[mid - 1]) / 2.0;
    }
    if (n2 == 0) {
        int mid = n1 >> 1;
        if (n1 & 1) return a1[mid];
        return (a1[mid] + a1[mid - 1]) / 2.0;
    }
    if (n1 == 1) return a1[0];
    if (n2 == 1) return a2[0];
    if (n1 + n2 == 2) return (a1[0] + a2[0]) / 2.0;
    int n = n1 + n2;
    int k = n >> 1;
    int i = 0, j = 0, ti, tj;
    double res = 0;
    while (k) {
        if (k == 1) {
            if (a1[i] < a2[j]) ++i;
            else ++j;
            break;
        }
        ti = min(k >> 1, n1 - i);
        tj = min(k >> 1, n2 - j);
        if (a1[i + ti - 1] < a2[j + tj - 1]) {
            i += ti;
            k -= ti;
            if (i == n1) {
                if (n & 1) res = a2[j + k];
                else res = (a2[j + k - 1] + a2[j + k]) / 2.0;
                return res;
            }
        } else {
            j += tj;
            k -= tj;
            if (j == n2) {
                if (n & 1) res = a1[i + k];
                else res = (a1[i + k - 1] + a1[i + k]) / 2.0;
                return res;
            }
        }
    }
    if (n & 1) {
        if (i == n1) return a2[j];
        if (j == n2) return a1[i];
        res = min(a1[i], a2[j]);
    } else {
        if (i == n1) res = a2[j];
        else if (j == n2) res = a1[i];
        else res = min(a1[i], a2[j]);
        if (i == 0) res += a2[j - 1];
        else if (j == 0) res += a1[i - 1];
        else res += max(a1[i - 1], a2[j - 1]);
        res /= 2.0;
    }
    return res;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n1 >> n2;
        for (int i = 0; i < n1; i++) cin >> a1[i];
        for (int i = 0; i < n2; i++) cin >> a2[i];
        cout << solve() << endl;
    }
    return 0;
}