/**
 *    author:  skmonir
 *    created: 21-Sep-2017 01:05:22
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

const int N = 256;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};


int n, T, a[N][N], b[N][N];

struct data {
    int t, r;
    data() : r(INF), t(INF) {}
    data(int _t, int _r) : t(_t), r(_r) {}
    bool operator < (const data &x) const {
        if (t > T and x.t > T) return r < x.r;
        if (t > T) return false;
        if (x.t > T) return true;
        return r == x.r ? t < x.t : r < x.r;
    }
} dp[N][N];

int main() {
    int tc; Int(tc);
    while (tc--) {
        Int(n, T);
        FOR (i, 1, n) FOR (j, 1, n) Int(a[i][j]);
        FOR (i, 1, n) FOR (j, 1, n) Int(b[i][j]);

        FOR (t, 0, T) FOR (i, 1, n) dp[t][i] = data();
        FOR (t, 0, T) dp[t][1] = data(0, 0);

        FOR (t, 1, T) FOR (i, 1, n) FOR (j, 1, n) {
            if (i == j or a[j][i] > t) continue;
            data now = data();
            now.t = a[j][i] + dp[t - a[j][i]][j].t;
            now.r = b[j][i] + dp[t - a[j][i]][j].r;
            if (now < dp[t][i]) dp[t][i] = now;
        }

        if (dp[T][n].t > T) printf("-1\n");
        else printf("%d %d\n", dp[T][n].r, dp[T][n].t);
    }
    return 0;
}
