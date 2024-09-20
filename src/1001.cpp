#include <bits/stdc++.h>
using namespace std;

int n, ans, len;
string s;

int main() {
    scanf("%d\n", &n);
    while (n--) {
        ans = 0;
        getline(cin, s);
        len = s.size();
        for (int i = 0; i < len; i++) {
            if (isdigit(s[i])) ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}