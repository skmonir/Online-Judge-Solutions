/**
 *    author:  skmonir
 *    created: 17-Sep-2017 16:47
**/
#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <typename T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

const int N = (int) 2e3 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

int dp[N][N];
vector <int> v[N], idx;

int LCS(vector <int> &a, vector <int> &b) {
    mem(dp, 0);
    FOR (i, 1, (int) a.size() - 1) {
        FOR (j, 1, (int) b.size() - 1) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) umax(dp[i][j], 1 + dp[i - 1][j - 1]);
        }
    }
    return dp[(int) a.size() - 1][(int) b.size() - 1];
}

int main() {
    int tc; Int(tc);
    while (tc--) {
        v[0].resize(N, 0);
        int m = 0;
        FOR (i, 1, N) {
            v[i].resize(1, 0);
            int x; Int(x);
            while (x) {
                v[i].push_back(x);
                Int(x);
            }
            if (v[i].size() == 1) break;
            m++;
        }
        int res = 0;
        FOR (i, 2, m) umax(res, LCS(v[1], v[i]));
        printf("%d\n", res);
    }
    return 0;
}
