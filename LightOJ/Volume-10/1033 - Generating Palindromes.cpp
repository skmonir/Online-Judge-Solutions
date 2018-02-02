/**
 *    author:  skmonir
 *    created: 01-Feb-2018 00:10:11
**/

#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <TN T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <TN T, TN W> inline void Int(T &x, W &y) {Int(x), Int(y);}
template <TN T, TN W, TN Q> inline void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = 1e2 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

char s[N];
int dp[N][N];

int DP(int x, int y) {
    if (x == y) return 0;
    if (x + 1 == y and s[x] == s[y]) return 0;

    int &res = dp[x][y];

    if (~res) return res;

    res = 0;

    if (s[x] == s[y]) res = DP(x + 1, y - 1);
    else res = 1 + min(DP(x + 1, y), DP(x, y - 1));

    return res;
}

int main() {
    int tc, ks = 0;
    Int(tc);

    while (tc--) {
        scanf("%s", s + 1);

        mem(dp, -1);

        printf("Case %d: %d\n", ++ks, DP(1, strlen(s + 1)));
    }

    return 0;
}
