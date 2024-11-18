#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int T;
int n;
struct Point {
    int x;
    int y;
} points[N], temp[N];
double disMin;

double calDis(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (points[i].y < points[j].y || (points[i].y == points[j].y && points[i].x < points[j].x)) {
            temp[k].x = points[i].x;
            temp[k++].y = points[i++].y;
        } else {
            temp[k].x = points[j].x;
            temp[k++].y = points[j++].y;
        }
    }
    while (i <= mid) {
        temp[k].x = points[i].x;
        temp[k++].y = points[i++].y;
    }
    while (j <= r) {
        temp[k].x = points[j].x;
        temp[k++].y = points[j++].y;
    }
    for (i = l; i <= r; i++) {
        points[i].x = temp[i].x;
        points[i].y = temp[i].y;
    }
}

void solve(int l, int r) {
    if (r - l + 1 <= 4) {
        for (int i = l; i <= r; i++) {
            for (int j = i + 1; j <= r; j++) {
                disMin = min(disMin, calDis(points[i], points[j]));
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    int xMid = points[mid].x;
    solve(l, mid);
    solve(mid + 1, r);
    merge(l, mid, r);

    vector<int> tmp;
    // double tmpDis = disMin;
    for (int i = l, j; i <= r; i++) {
        if (1.0 * abs(points[i].x - xMid) >= disMin) continue;
        // j = tmp.size() - 1;
        // while (j >= 0 && points[i].y - points[tmp[j]].y <= disMin) {
        //     tmpDis = min(tmpDis, calDis(points[i], points[tmp[j]]));
        //     --j;
        // }
        tmp.push_back(i);
    }
    // disMin = min(disMin, tmpDis);
    int sz = tmp.size();
    for (int i = 0; i < sz; i++) {
        for (int j = max(0, i - 6); j < i; j++) {
            disMin = min(disMin, calDis(points[tmp[i]], points[tmp[j]]));
        }
    }
}

inline bool cmpX(const Point &a, const Point &b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &points[i].x, &points[i].y);
        }
        sort(points + 1, points + n + 1, cmpX);
        if (n > 1) {
            disMin = calDis(points[1], points[2]);
        } else {
            disMin = 2e9;
        }
        solve(1, n);
        printf("%.2lf\n", disMin);
    }
    return 0;
}