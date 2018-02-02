/**
 *    author:  skmonir
 *    created: 01-Feb-2018 11:45:47
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

const int N = 7e4 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

int n, a[17][17], dp[17][N];

int DP(int i, int mask) {
    if (i > n) return 0;

    if (~dp[i][mask]) return dp[i][mask];

    dp[i][mask] = 0;

    FOR (j, 0, n) if (!(mask & (1 << j))) {
        int newMask = mask | (1 << j);
        umax(dp[i][mask], a[i][j] + DP(i + 1, newMask));
    }

    return dp[i][mask];
}

int main() {
    //freopen("input_.txt", "r", stdin);
    int tc, ks = 0;
    Int(tc);

    while (tc--) {
        mem(dp, -1);

        Int(n); n--;
        FOR (i, 0, n) FOR (j, 0, n) Int(a[i][j]);

        printf("Case %d: %d\n", ++ks, DP(0, 0));
    }

    return 0;
}
