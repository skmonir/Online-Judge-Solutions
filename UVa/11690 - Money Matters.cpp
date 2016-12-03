#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e5 + 5;

struct UnionFind {
    int sz[N], par[N], val[N];
    void initialize(int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d", val + i);
            sz[i] = 1, par[i] = i;
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
        val[u] += val[v];
    }
} helper;

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int n, m;
        scanf("%d%d", &n, &m);
        helper.initialize(n);
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            helper.merge(u, v);
        }
        bool foo = true;
        for (int i = 0; i < n; i++) {
            int u = helper.root(i);
            if (helper.val[u] != 0) foo = false;
        }
        puts(foo ? "POSSIBLE" : "IMPOSSIBLE");
    }
}
