#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 2e4 + 5;

int T, n, m;
int fa[N];
class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w);
    bool operator> (const Edge& e) const;
};

int getFa(int x);

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        for (int i = 1, u, v, w; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            pq.push(Edge(u, v, w));
        }
        for (int i = 1; i <= n; i++) fa[i] = i;
        int countConnected = n, ans = 0;
        while (countConnected > 1 && !pq.empty()) {
            Edge e = pq.top();
            pq.pop();
            int fau = getFa(e.u);
            int fav = getFa(e.v);
            if (fau != fav) {
                fa[fav] = fau;
                ans += e.w;
                --countConnected;
            }
        }
        if (countConnected != 1) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}

Edge::Edge(int u, int v, int w) {
    this->u = min(u, v);
    this->v = max(u, v);
    this->w = w;
}

bool Edge::operator> (const Edge& e) const {
    return this->w > e.w;
}

int getFa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = getFa(fa[x]);
}