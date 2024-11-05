#include<bits/stdc++.h>
using namespace std;

const int LENGTH = 1e4 + 5;

int T, n, m, f[LENGTH];
struct Piece {
    int len, price;
    Piece(int l, int p) : len(l), price(p) {};
};

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        vector<Piece> pieces;
        for (int i = 1, l, p; i <= m; i++) {
            scanf("%d%d", &l, &p);
            if (l > n) continue;
            pieces.push_back(Piece(l, p));
        }
        memset(f, 0x00, sizeof(f));
        for (Piece piece : pieces) {
            for (int i = piece.len; i <= n; i++) {
                f[i] = max(f[i], f[i - piece.len] + piece.price);
            }
        }
        printf("%d\n", f[n]);
    }
    return 0;
}