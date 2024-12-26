#include <bits/stdc++.h>
using namespace std;

namespace netwf {

struct Edge {
    int to;
    int flow;
    int cost;
    int nextEdge;
    Edge(int u, int v, int f, int c, int* h, int &cnt) {
        nextEdge = h[u];
        to = v;
        flow = f;
        cost = c;
        h[u] = cnt++;
    }
};

struct Graph {
    int n, m;
    int *head;
    vector<Edge> edge;
    Graph(int vertexNum): n(vertexNum), m(0) {
        head = (int *) malloc(n * sizeof(int));
        memset(head, -1, n * sizeof(int));
        edge.clear();
    }
    void addEdge(int u, int v, int f, int c) {
        edge.push_back(Edge(u, v, f, c, head, m));
        edge.push_back(Edge(v, u, 0, -c, head, m));
    }
};

class Problem {
public:
    Problem(Graph &g, int s, int t): graph(g), s(s), t(t) {
        n = g.n;
        flow = (int *) malloc(n * sizeof(int));
        dis = (int *) malloc(n * sizeof(int));
        pre = (int *) malloc(n * sizeof(int));
        linked = (int *) malloc(n * sizeof(int));
        vis = (int *) malloc(n * sizeof(int));
    }
private:
    Graph graph;
    int s; // source, default 0
    int t; // sink, defulat n-1
    int n; // number of vertices, including source and sink
    int *flow, *dis, *pre, *linked, *vis;
    int maxflow, mincost;
    bool spfa(int s, int t) {
        memset(flow, 0x3f, n * sizeof(int));
        memset(dis, 0x3f, n * sizeof(int));
        memset(vis, 0x00, n * sizeof(int));
        pre[t] = -1;
        queue<int> q;
        q.push(s);
        vis[s] = 1;
        dis[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = graph.head[u], v; ~i; i = graph.edge[i].nextEdge) {
                v = graph.edge[i].to;
                if (graph.edge[i].flow > 0 && dis[v] > dis[u] + graph.edge[i].cost) {
                    dis[v] = dis[u] + graph.edge[i].cost;
                    pre[v] = u;
                    linked[v] = i;
                    flow[v] = min(flow[u], graph.edge[i].flow);
                    if (!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                    }
                }
            }
        }
        return pre[t] != -1;
    }
    void mcmf() {
        maxflow = 0;
        mincost = 0;
        while (spfa(s, t)) {
            int p = t;
            maxflow += flow[t];
            mincost += flow[t] * dis[t];
            while (p != s) {
                graph.edge[linked[p]].flow -= flow[t];
                graph.edge[linked[p] ^ 1].flow += flow[t];
                p = pre[p];
            }
        }
    }
public:
    void mcmf(int &mf, int &mc) {
        mcmf();
        mf = maxflow;
        mc = mincost;
    }
};

}

const int N = 55;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        int price[N][N];
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> price[i][j]; // i: woman; j: man
            }
        }
        netwf::Graph g = netwf::Graph(n + m + 2);
        for (int i = 1, k; i <= n; i++) {
            cin >> k;
            for (int j = 1, t; j <= k; j++) {
                cin >> t;
                g.addEdge(i, t + n, 1, price[t][i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            g.addEdge(0, i, 1, 0);
        }
        for (int i = n + 1, t = n + m + 1; i <= n + m; i++) {
            g.addEdge(i, t, 1, 0);
        }
        netwf::Problem p = netwf::Problem(g, 0, n + m + 1);
        int maxPair = 0, minCost = 0;
        p.mcmf(maxPair, minCost);
        cout << maxPair << " " << minCost << "\n";
    }
    return 0;
}