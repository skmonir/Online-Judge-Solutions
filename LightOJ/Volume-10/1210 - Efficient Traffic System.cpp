#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;


stack <int> stk;
vector <int> g[N];
int scc, timer, ks;
int in[N], out[N], used[N];
int enter[N], low[N], SCC[N];

void Tarjan(int u) {
    stk.push(u);
    low[u] = enter[u] = ++timer;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (SCC[v]) continue;
        if (enter[v]) low[u] = min(low[u], enter[v]);
        else {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == enter[u]) {
        int v; scc++;
        do {
            v = stk.top(); stk.pop();
            SCC[v] = scc;
        } while (u != v);
    }
}

void dfs(int from) {
    used[from] = 1;
    for (int i = 0; i < g[from].size(); i++) {
        int to = g[from][i];
        if (SCC[from] != SCC[to]) {
            in[SCC[to]]++;
            out[SCC[from]]++;
        }
        if (!used[to]) dfs(to);
    }
}

void refresh() {
    while (stk.size()) stk.pop();
    scc = timer = 0;
    for (int i = 0; i < N; i++) {
        g[i].clear();
        in[i] = out[i] = used[i] = 0;
        enter[i] = low[i] = SCC[i] = 0;
    }
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        refresh();
        int n, m;
        scanf("%d%d", &n, &m);
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) {
            if (!enter[i]) Tarjan(i);
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) dfs(i);
        }
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= scc && scc > 1; i++) {
            if (!in[i]) c1++;
            if (!out[i]) c2++;
        }
        printf("Case %d: %d\n", ++ks, max(c1, c2));
    }
}
