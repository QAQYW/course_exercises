#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int M = 10005;

typedef pair<int, int> pii;

int T, n, m, s, t;
int head[N], cnt;
int dis[N], vis[N];
struct Edge {
    int to, nxt, cst;
    void add(int u, int v, int w) {
        nxt = head[u];
        to = v;
        head[u] = cnt++;
        cst = w;
    }
} edges[M << 1];

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0x00, sizeof(vis));
    dis[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u], v; ~i; i = edges[i].nxt) {
            if (dis[u] + edges[i].cst < dis[v = edges[i].to]) {
                dis[v] = dis[u] + edges[i].cst;
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        // read
        cin >> n >> m >> s >> t;
        cnt = 0;
        memset(head, -1, sizeof(head));
        for (int i = 1, u, v, w; i <= m; i++) {
            cin >> u >> v >> w;
            edges[cnt].add(u, v, w);
            edges[cnt].add(v, u, w);
        }

        // solve
        dijkstra();

        // output
        if (dis[t] == dis[n + 1]) puts("-1");
        else cout << dis[t] << "\n";
    }
    return 0;
}