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
        if (sz[u] > sz[v]) swap(u, v);
        par[v] = u, sz[u] += sz[v];
    }
} helper;

int main() {
    int tc, line = 0;
    scanf("%d", &tc);
    while (tc--) {
        int n, yes = 0, no = 0;
        scanf("\n%d\n", &n);
        helper.initialize(n);
        while (true) {
            string s;
            char ch; int x, y;
            if (!getline(cin, s) || s.empty()) break;
            sscanf(s.c_str(), "%c %d %d", &ch, &x, &y);
            int u = helper.root(x);
            int v = helper.root(y);
            if (ch == 'c') {
                if (u != v) helper.merge(u, v);
            } else {
                if (u == v) yes++;
                else no++;
            }
        }
        if (line++) putchar('\n');
        printf("%d,%d\n", yes, no);
    }
}
