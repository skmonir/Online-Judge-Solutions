#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e6 + 5;

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
    int n, m;
    while (scanf("%d%d", &n, &m) && (n + m)) {
        vector <int> v;
        helper.initialize(n);
        while (m--) {
            v.clear();
            int k, x, foo = 0, sus = helper.root(0);
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &x);
                if (helper.root(x) == sus) foo = 1;
                v.push_back(x);
            }
            if (foo) {
                for (int i = 0; i < v.size(); i++) {
                    helper.merge(0, v[i]);
                }
            } else {
                for (int i = 1; i < v.size(); i++) {
                    helper.merge(v[i], v[i - 1]);
                }
            }
        }
        printf("%d\n", helper.sz[helper.root(0)]);
    }
}
