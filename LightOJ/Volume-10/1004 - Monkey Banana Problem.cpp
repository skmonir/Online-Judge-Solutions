#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

int a[223][223], dp[223][223];

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        mem(a, 0), mem(dp, 0);
        int n, m; scanf("%d", &m);
        n = 2 * m - 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= i; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= m - i; j++) {
                scanf("%d", &a[i + m][j + i]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
        printf("Case %d: %d\n", ++ks, dp[n][m]);
    }
    return 0;
}
