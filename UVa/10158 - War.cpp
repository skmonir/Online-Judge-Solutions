#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e6 + 5;

int EnemyID[N];

struct UnionFind {
    int par[N], sz[N];
    void initialize(int n) {
        for (int i = 0; i <= 2 * n; i++) {
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
} dsu;

int main() {
    int n; scanf("%d", &n);
    dsu.initialize(n);
    for (int i = 0; i < n; i++) EnemyID[i] = i + n;
    int t, x, y;
    while (scanf("%d%d%d", &t, &x, &y)) {
        if (!(x + y + t)) break;
        if (t == 1) {
            if (dsu.root(x) == dsu.root(EnemyID[y])) puts("-1");
            else if (dsu.root(y) == dsu.root(EnemyID[x])) puts("-1");
            else dsu.merge(x, y), dsu.merge(EnemyID[x], EnemyID[y]);
        } else if (t == 2) {
            if (dsu.root(x) == dsu.root(y)) puts("-1");
            else if (dsu.root(EnemyID[x]) == dsu.root(EnemyID[y])) puts("-1");
            else dsu.merge(EnemyID[x], y), dsu.merge(x, EnemyID[y]);
        } else if (t == 3) {
            bool foo = dsu.root(x) == dsu.root(y);
            bool boo = dsu.root(EnemyID[x]) == dsu.root(EnemyID[y]);
            printf("%d\n", foo || boo);
        } else {
            bool foo = dsu.root(x) == dsu.root(EnemyID[y]);
            bool boo = dsu.root(EnemyID[x]) == dsu.root(y);
            printf("%d\n", foo || boo);
        }
    }
}
