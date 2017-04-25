#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()

const LL MOD = 1000000007;
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 200 + 5;


int n, m, f, col[N];
vector <int> g[N];

void dfs(int u, int c) {
    col[u] = c;
    for (auto v : g[u]) {
        if (col[v] == col[u]) f = false;
        if (!col[v]) dfs(v, 3 - col[u]);
    }
}

int main() {
    while (scanf("%d", &n) and n) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
            col[i] = 0;
        }
        scanf("%d", &m);
        while (m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        f = true;
        dfs(0, 1);
        puts(f ? "BICOLORABLE." : "NOT BICOLORABLE.");
    }
    return 0;
}
