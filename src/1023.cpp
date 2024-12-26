#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int FI = 105;
const int inf = 0x3f3f3f3f;

int T;
int n, m, s, t, fi;
int edge[N][N];
int cost[N];
struct Node {
    int pos, money;
    Node(int p, int m): pos(p), money(m) {}
};

int spfa() {
    bool vis[N][FI];
    int dis[N][FI];
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    memset(dis[s], 0x00, sizeof(dis[s]));
    int res = dis[t][0];
    queue<Node> q;
    q.push(Node(s, fi));
    vis[s][fi] = 1;
    while (!q.empty()) {
        Node u = q.front();
        q.pop();
        vis[u.pos][u.money] = 0;
        for (int v = 1; v <= n; v++) {
            if (v == u.pos || edge[u.pos][v] == -1) continue;
            if (u.money < cost[v]) continue;
            if (dis[v][u.money - cost[v]] > dis[u.pos][u.money] + edge[u.pos][v]) {
                dis[v][u.money - cost[v]] = dis[u.pos][u.money] + edge[u.pos][v];
                if (!vis[v][u.money - cost[v]]) {
                    q.push(Node(v, u.money - cost[v]));
                    vis[v][u.money - cost[v]] = 1;
                }
            }
        }
    }
    for (int i = 0; i <= fi; i++) res = min(res, dis[t][i]);
    if (res == inf) return -1;
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(edge, 0x3f, sizeof(edge));
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &fi);
        for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
        for (int i = 1, u, v, w; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            edge[u][v] = min(edge[u][v], w);
            edge[v][u] = edge[u][v];
        }
        printf("%d\n", spfa());
    }
    return 0;
}