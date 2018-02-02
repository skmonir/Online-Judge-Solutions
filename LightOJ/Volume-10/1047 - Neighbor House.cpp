/**
 *    author:  skmonir
 *    created: 01-Feb-2018 14:49:12
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

const int N = 1e5 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

int w[22][5], dp[22][5];
int main() {
    int tc, ks = 0;
    Int(tc);

    while (tc--) {
        int n; Int(n);
        FOR (i, 1, n) {
            Int(w[i][1], w[i][2], w[i][3]);
        }

        dp[1][1] = w[1][1], dp[1][2] = w[1][2], dp[1][3] = w[1][3];
        FOR (i, 2, n) {
            dp[i][1] = w[i][1] + min(dp[i - 1][2], dp[i - 1][3]);
            dp[i][2] = w[i][2] + min(dp[i - 1][1], dp[i - 1][3]);
            dp[i][3] = w[i][3] + min(dp[i - 1][1], dp[i - 1][2]);
        }

        printf("Case %d: %d\n", ++ks, min(dp[n][1], min(dp[n][2], dp[n][3])));
    }

    return 0;
}
