#include <bits/stdc++.h>
 
using namespace std;
 
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
 
const LL MOD = 1000000007;
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 2e2 + 5;
 
LL dp[N][N];
int n, sz[N];
vector <LL> a[N];
 
void init() {
    for (int i = 0; i < 2 * N; i++) {
        a[i].clear();
        sz[i] = 0;
    }
    memset(dp, -1, sizeof dp);
}
 
inline bool invalid(int x, int y) {
    return x > 2 * n || y >= sz[x] || !a[x][y];
}
 
LL DP(int x, int y) {
    if (invalid(x, y)) return 0;
    LL &res = dp[x][y];
    if (~res) return res;
    res = max(a[x][y] + DP(x + 1, y), a[x][y] + DP(x + 1, y + 1));
    return res;
}
 
int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        init();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                LL x; scanf("%lld", &x);
                a[i - 1].push_back(x);
            }
        }
        for (int i = 1; i <= n - 1; i++) {
            for (int j = 1; j <= i; j++) a[n + i - 1].push_back(0);
            for (int j = 1; j <= n - i; j++) {
                LL x; scanf("%lld", &x);
                a[n + i - 1].push_back(x);
            }
        }
        for (int i = 0; i < 2 * n - 1; i++) sz[i] = a[i].size();
        printf("Case %d: %lld\n", ++ks, DP(0, 0));
    }
    return 0;
}
