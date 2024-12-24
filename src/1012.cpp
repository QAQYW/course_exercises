#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int T;
int n;
struct Point {
    int x, y;
    void print() {
        printf("%d %d\n", x, y);
    }
} points[N];
int stk[N], tp;

bool cmp_yx(const Point &a, const Point &b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

// cross product
double cross(const Point &a, const Point &b, const Point &c, const Point &d) {
    // (a->b) * (c->d)
    return (b.x - a.x) * (d.y - c.y) - (d.x - c.x) * (b.y - a.y);
}

// sqr(dist)
int dist2(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp_angle(const Point &a, const Point &b) {
    double tmp = cross(points[1], a, points[1], b);
    if (tmp > 0) return true;
    if (tmp < 0) return false;
    return dist2(points[0], a) < dist2(points[0], b);
}

bool in_line(const Point &a, const Point &b, const Point &c) {
    if (b.x == a.x) {
        if (c.x == a.x) return true;
        return false;
    }
    if (c.x == a.x) return false;
    double t1 = (b.y - a.y) * 1.0 / (b.x - a.x);
    double t2 = (c.y - a.y) * 1.0 / (c.x - a.x);
    if (t1 == t2) return true;
    return false;
}

int main() {
    points[0].x = points[0].y = 0;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        int lowerLeft = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &points[i].x, &points[i].y);
            if (points[i].y < points[lowerLeft].y || (points[i].y == points[lowerLeft].y && points[i].x < points[lowerLeft].x)) {
                lowerLeft = i;
            }
        }
        if (lowerLeft != 1) {
            swap (points[lowerLeft].x, points[1].x);
            swap (points[lowerLeft].y, points[1].y);
        }
        stk[tp = 1] = 1;
        sort(points + 2, points + n + 1, cmp_angle);
        for (int i = 2; i <= n; i++) {
            while (tp > 1 && cross(points[stk[tp - 1]], points[stk[tp]], points[stk[tp]], points[i]) <= 0) --tp;
            stk[++tp] = i;
        }
        printf("case %d:\n", cas);
        for (int i = 1; i <= tp; i++) points[stk[i]].print();
        // points[1].print();
        // for (int i = 2; i < tp; i++) {
        //     if (!in_line(points[stk[i - 1]], points[stk[i]], points[stk[i + 1]])) points[stk[i]].print();
        // }
        // if (!in_line(points[stk[tp - 1]], points[stk[tp]], points[1])) points[stk[tp]].print();
    }
    return 0;
}