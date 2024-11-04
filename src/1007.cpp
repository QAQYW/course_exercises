#include <bits/stdc++.h>

namespace big_int {

class Int {
public:
    int dig[50];
    int count;
    Int();
    Int(std::string s);
    void carry();
    void println() const;
};

Int Max(const Int& a, const Int& b);
Int Mul(const Int& a, const Int& b);

} // end of namespace big_int

int T;
big_int::Int ans;
big_int::Int f[45][10];

int main() {
    std::cin >> T;
    int n, k, len;
    std::string str;
    while (T--) {
        std::cin >> n >> k >> str;
        ans = big_int::Int("0");
        len = str.size();
        for (int i = 0; i < len; i++) {
            int jMax = std::min(i, k);
            // printf("f[%d][0]: ", i);
            f[i][0] = big_int::Int(str.substr(0, i + 1));
            // f[i][0].println();
            for (int j = 1; j <= jMax; j++) {
                // printf("f[%d][%d]: ", i, j);
                f[i][j] = big_int::Int("0");
                for (int l = i - 1; l >= j - 1; l--) {
                    big_int::Int tmp = big_int::Mul(f[l][j - 1], big_int::Int(str.substr(l + 1, i - l)));
                    // tmp.println();
                    f[i][j] = big_int::Max(f[i][j], tmp);
                }
                // f[i][j].println();
            }
        }
        f[len - 1][k].println();
    }
    // std::cout << "over!\n";
    return 0;
}

big_int::Int::Int() : count(0) {
    memset(dig, 0x00, sizeof(dig));
}

big_int::Int::Int(std::string s) {
    // std::cout << "init: " << s << "\n";
    memset(dig, 0x00, sizeof(dig));
    count = s.size();
    while (count > 1 && s[0] == '0') {
        s = s.substr(1);
    }
    for (int i = 0; i < count; i++) {
        dig[i] = s[count - i - 1] - '0';
    }
}

void big_int::Int::carry() {
    for (int i = 0; i < count; i++) {
        if (dig[i] > 9) {
            dig[i + 1] += dig[i] / 10;
            dig[i] %= 10;
        }
    }
    if (count > 0 && dig[count - 1] == 0) --count;
}

void big_int::Int::println() const {
    for (int i = count - 1; ~i; i--)
        std::cout << dig[i];
    std::puts("");
}

big_int::Int big_int::Max(const big_int::Int& a, const big_int::Int& b) {
    if (a.count > b.count) return big_int::Int(a);
    if (b.count > a.count) return big_int::Int(b);
    for (int i = a.count - 1; ~i; i--) {
        if (a.dig[i] > b.dig[i]) return big_int::Int(a);
        if (b.dig[i] > a.dig[i]) return big_int::Int(b);
    }
    return big_int::Int(a);
}

big_int::Int big_int::Mul(const big_int::Int& a, const big_int::Int& b) {
    // std::cout << "Mul:\n";a.println();b.println();
    if (a.count == 0 || b.count == 0) {
        // std::cout << "error: factor disappear!\n";
        return big_int::Int();
    }
    big_int::Int res = Int();
    for (int i = 0; i < a.count; i++) {
        for (int j = 0; j < b.count; j++) {
            res.dig[i + j] += a.dig[i] * b.dig[j];
        }
    }
    res.count = a.count + b.count;
    res.carry();
    return res;
}
