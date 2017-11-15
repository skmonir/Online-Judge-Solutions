/**
 *    author:  skmonir
 *    created: 15-Nov-2017 01:19:31
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


string s;
int a, b, k, dp[10][2][100][100];

int DP(int i, int f, int r1, int r2) {
    if (i == s.size()) return !r1 && !r2;
    int &res = dp[i][f][r1][r2];
    if (~res) return res;

    int lim = f ? s[i] - '0' : 9;
    res = 0;
    FOR (j, 0, lim) {
        res += DP(i + 1, f && (j == lim), ((r1 * 10) % k + j) % k, (r2 + j) % k);
    }
    return res;
}

string int_to_str(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
}

int main() {
    int tc, ks = 0; Int(tc);
    while (tc--) {
        scanf("%d %d %d", &a, &b, &k);
        printf("Case %d: ", ++ks);
        if (k > 99) {
            puts("0"); continue;
        }

        mem(dp, -1);
        s = int_to_str(b);
        int res = DP(0, 1, 0, 0);

        mem(dp, -1);
        s = int_to_str(a - 1);
        res -= DP(0, 1, 0, 0);

        printf("%d\n", res);
    }
    return 0;
}
