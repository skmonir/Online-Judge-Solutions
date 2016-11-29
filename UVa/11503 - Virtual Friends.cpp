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
    int par[N], sz[N];
    void initialize(int n) {
        for (int i = 0; i < N; i++) {
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
    int tc; scanf("%d", &tc);
    while (tc--) {
        int id = 1, n;
        scanf("%d", &n);
        map <string, int> ID;
        helper.initialize(n);
        while (n--) {
            string s, t;
            cin >> s >> t;
            if (ID[s] == 0) ID[s] = id++;
            if (ID[t] == 0) ID[t] = id++;
            helper.merge(ID[s], ID[t]);
            printf("%d\n", helper.sz[helper.root(ID[s])]);
        }
    }
}
