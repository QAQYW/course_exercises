#include<bits/stdc++.h>
using namespace std;

// ! 未完成

const int N = 505;
const int FI = 105;

int T;
int n, m, s, t, fi;
int edge[N][N];
int cost[N];
// bool vis[N][FI];
struct Node {
    int pos, money, dis;
    Node(int p, int m, int d): pos(p), money(m), dis(d) {}
    bool operator< (const Node &another) const {
        return dis < another.dis;
    }
};

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(edge, -1, sizeof(edge));
        // memset(vis, false, sizeof(vis));
        scanf("%d%d%d%d%d", &n, &m, &s, &t, &fi);
        for (int i = 1; i <= n; i++) scanf("%d", &cost[i]);
        for (int i = 1, u, v, w; i <= m; i++) {
            scanf("%d%d%d", &u, &v, &w);
            if (edge[u][v] == -1) {
                edge[u][v] = w;
                edge[v][u] = w;
            } else {
                edge[u][v] = min(edge[u][v], w);
                edge[v][u] = edge[u][v];
            }
        }
        int res = -1;
        priority_queue<Node, vector<Node>, less<Node> > pq;
        pq.push(Node(s, fi, 0));
        while (!pq.empty()) {
            Node u = pq.top();
            pq.pop();
            if (u.pos == t) {
                if (res == -1) res = u.dis;
                else res = min(res, u.dis);
            }
            for (int v = 1; v <= n; v++) {
                if (v == u.pos || edge[u.pos][v] == -1) continue;
                if (cost[v] <= u.money) {
                    // if (!vis[v][u.money - cost[v]]) {
                        pq.push(Node(v, u.money - cost[v], u.dis + edge[u.pos][v]));
                    // }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}