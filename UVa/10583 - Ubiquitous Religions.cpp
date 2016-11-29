#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e5 + 5;


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
    int n, m, ks = 0;
    while (scanf("%d%d", &n, &m) && (m + n)) {
        fill(used, 0);
        helper.initialize(n);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            helper.merge(x, y);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int u = helper.root(i);
            if (!used[u]) used[u]++, ans++;
        }
        printf("Case %d: %d\n", ++ks, ans);
    }
}
