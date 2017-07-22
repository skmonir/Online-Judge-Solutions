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


int in[N];
vector <int> g[N];

int dfs(int u) {
    int mx = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        umax(mx, dfs(v));
    }
    return mx + 1;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            in[i] = 0; g[i].clear();
        }
        int n, m; scanf("%d%d", &n, &m);
        while (m--) {
            int u, v; scanf("%d%d", &u, &v);
            in[v]++;
            g[u].push_back(v);
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) umax(mx, dfs(i));
        }
        printf("Case %d: %d\n", ++ks, mx);
    }
    return 0;
}
