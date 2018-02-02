/**
 *    author:  skmonir
 *    created: 31-Jan-2018 16:26:43
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

long long dp[66][66];

int main() {
    int tc, ks = 0;
    Int(tc);

    while (tc--) {
        static char s[66];
        scanf("%s", s + 1);

        mem(dp, 0);
        int len = strlen(s + 1);

        FOR (i, 1, len) dp[i][i] = 1;
        FOR (i, 2, len) dp[i - 1][i] = 2 + (s[i - 1] == s[i]);
        FOR (i, 3, len) FOR (j, i, len) {
            dp[j - i + 1][j] = dp[j - i + 2][j] + dp[j - i + 1][j - 1] - dp[j - i + 2][j - 1];
            if (s[j - i + 1] == s[j]) dp[j - i + 1][j] += dp[j - i + 2][j - 1] + 1;
        }

        printf("Case %d: %lld\n", ++ks, dp[1][len]);
    }

    return 0;
}
