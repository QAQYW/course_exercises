#include<bits/stdc++.h>
using namespace std;

const int LEN = 1e5 + 5;

int T;
int slen, tlen;
string s, t;

int kmp(string s, string t) {
    s = "#" + s;
    t = "#" + t;
    vector<int> next(tlen + 1, 0);
    for (int i = 2, j = 0; i <= tlen; i++) {
        while (j && t[i] != t[j + 1]) j = next[j];
        if (t[i] == t[j + 1]) ++j;
        next[i] = j;
    }
    int count = 0;
    for (int i = 1, j = 0; i <= slen; i++) {
        while (j && (s[i] != t[j + 1] || j == tlen)) j = next[j];
        if (s[i] == t[j + 1]) ++j;
        if (j == tlen) ++count;
    }
    return count;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> slen >> tlen >> s >> t;
        cout << kmp(s, t) << "\n";
    }
    return 0;
}