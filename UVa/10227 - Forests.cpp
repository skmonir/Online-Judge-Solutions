#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e3 + 5;

set <int> g[N];
int used[N];

struct UnionFind {
    int par[N], sz[N];
    void initialize(int n) {
        for (int i = 0; i <= n; i++) {
            par[i] = i, sz[i] = 1;
        }
    }
    int root(int u) {
        return par[u] == u ? u : par[u] = root(par[u]);
    }
    void merge(int u, int v) {
        u = root(u), v = root(v);
        if (u == v) return;
        if (sz[u] > sz[v]) swap(u, v);
        par[v] = u, sz[u] += sz[v];
    }
} helper;

int main() {
    int tc, ks = 0; scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            g[i].clear(); used[i] = 0;
        }
        int n, m;
        scanf("\n%d%d\n", &n, &m);
        helper.initialize(n);
        string s;
        while (true) {
            if (!getline(cin, s) || s.empty()) break;
            int u, v;
            sscanf(s.c_str(), "%d %d", &u, &v);
            g[u].insert(v);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (g[i].size() != g[j].size()) continue;
                if (g[i] == g[j]) helper.merge(i, j);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int u = helper.root(i);
            if (!used[u]) used[u]++, ans++;
        }
        if (ks++) putchar(endl);
        printf("%d\n", ans);
    }
}
