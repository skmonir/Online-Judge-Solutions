/**
 *    author:  skmonir
 *    created: 21-Sep-2017 15:43:52
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

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

long long a[N], dp[2][N];

int main() {
    int tc, ks = 0;
    Int(tc);
    while (tc--) {
        mem(dp, 0);
        int n; Int(n);
        FOR (i, 1, n) Int(a[i]);

        FOR (i, 1, n) {
            dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
            dp[1][i] = a[i] + max(dp[1][i - 2], dp[0][i - 1]);
        }
        printf("Case %d: %lld\n", ++ks, max(dp[0][n], dp[1][n]));
    }
    return 0;
}
