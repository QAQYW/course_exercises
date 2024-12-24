#include<bits/stdc++.h>
using namespace std;

int T;
string s1, s2;
int len1, len2, f[505][505];

int main() {
    scanf("%d", &T);
    while (T--) {
        cin >> s1 >> s2;
        len1 = s1.size();
        len2 = s2.size();
        s1 = "#" + s1;
        s2 = "#" + s2;
        memset(f, 0x00, sizeof(f));
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (s1[i] == s2[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        printf("%d\n", f[len1][len2]);
    }
    return 0;
}