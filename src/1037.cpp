#include<bits/stdc++.h>
using namespace std;

const int N = 55;

int path(int u, vector<bool> &vis, vector<int> &match, const vector<int> edge[]) {
    vis[u] = true;
    for (int v : edge[u]) {
        if (match[v] == -1) return match[v] = u;
        if (!vis[match[v]]) {
            if (~path(match[v], vis, match, edge)) return match[v] = u;
        }
    }
    return -1;
}

int km(int n, int m, const vector<int> edge[]) {
    int ans = 0;
    vector<int> match(n + m, -1);
    for (int i = 0; i < n; i++) {
        vector<bool> vis(n + m, false);
        if (~path(i, vis, match, edge)) ++ans;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> edge[n + m];
        for (int u = 0, k, v; u < n; u++) {
            cin >> k;
            for (int j = 0; j < k; j++) {
                cin >> v;
                v = n + v - 1;
                edge[u].push_back(v);
                edge[v].push_back(u);
            }
        }
        cout << km(n, m, edge) << "\n";
    }
    return 0;
}