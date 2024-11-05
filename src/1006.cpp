#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int T, n, hp[N];

#define lson (x << 1)
#define rson ((x << 1) | 1)

void adjust(int x) {
    if (rson <= n) {
        if (hp[lson] >= hp[x] && hp[rson] >= hp[x]) return;
        if (hp[lson] <= hp[rson]) { // 优先向左子树调整
            swap(hp[lson], hp[x]);
            adjust(lson);
        } else {
            swap(hp[rson], hp[x]);
            adjust(rson);
        }
        return;
    }
    if (lson <= n && hp[lson] < hp[x]) swap(hp[lson], hp[x]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &hp[i]);
        for (int i = n >> 1; i; i--) adjust(i);
        for (int i = 1; i <= n; i++) printf("%d ", hp[i]);
        puts("");
    }
    return 0;
}