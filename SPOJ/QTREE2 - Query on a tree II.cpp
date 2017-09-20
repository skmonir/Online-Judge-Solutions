#include <bits/stdc++.h>
 
using namespace std;
 
#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)
 
template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}
 
const int N = (int) 1e4 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;
 
vector < pair <int, int> > g[N];
int dep[N], dis[N], Par[N][25];
 
void dfs(int u, int p) {
    Par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= 20; i++) {
        Par[u][i] = Par[Par[u][i - 1]][i - 1];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (v != p) {
            dis[v] = dis[u] + w;
            dfs(v, u);
        }
    }
}
 
int lift_up(int u, int d) {
    for (int i = 20; i >= 0; i--) {
        if (d & (1 << i)) u = Par[u][i];
    }
    return u;
}
 
int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    a = lift_up(a, dep[a] - dep[b]);
    for (int i = 20; i >= 0; i--) {
        if (Par[a][i] != Par[b][i]) {
            a = Par[a][i], b = Par[b][i];
        }
    }
    return a == b ? a : Par[a][0];
}
 
int Dist(int u, int v) {
    return dis[u] + dis[v] - 2 * dis[LCA(u, v)];
}
 
int kth_parent(int u, int v, int k) {
    int lca = LCA(u, v);
    int d1 = dep[u] - dep[lca];
    int d2 = dep[v] - dep[lca];
    if (k <= d1 + 1) return lift_up(u, k - 1);
    else return lift_up(v, d2 - (k - d1 - 1));
}
 
int main() {
    //freopen("input_B.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
        }
 
        int n; scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        dfs(1, 0);
        char s[15];
        while (scanf("%s", s)) {
            if (s[1] == 'I') {
                int u, v;
                scanf("%d%d", &u, &v);
                printf("%d\n", Dist(u, v));
            } else if (s[0] == 'K') {
                int u, v, k;
                scanf("%d%d%d", &u, &v, &k);
                printf("%d\n", kth_parent(u, v, k));
            } else break;
        }
    }
    return 0;
}
