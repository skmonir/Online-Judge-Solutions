#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;


stack <int> stk;
int scc, timer, ks;
vector <int> g[N], gr[N];
int in[N], out[N], used[N], sz[N];
int enter[N], low[N], SCC[N], dp[N];

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
            SCC[v] = scc, sz[scc]++;
        } while (u != v);
    }
}

void dfs(int from) {
    used[from] = 1;
    for (int i = 0; i < g[from].size(); i++) {
        int to = g[from][i];
        if (SCC[from] != SCC[to]) {
            gr[from].push_back(to);
        }
        if (!used[to]) dfs(to);
    }
}

int DP(int cur) {
    if (dp[cur] != -1) return dp[cur];
    int res = 0;
    for (int i = 0; i < gr[cur].size(); i++) {
        res = max(res, DP(gr[cur][i]));
    }
    return dp[cur] = sz[SCC[cur]] + res;
}

void refresh() {
    while (stk.size()) stk.pop();
    scc = timer = 0;
    for (int i = 0; i < N; i++) {
        g[i].clear(); gr[i].clear();
        dp[i] = -1;
        in[i] = out[i] = used[i] = 0;
        enter[i] = low[i] = SCC[i] = sz[i] = 0;
    }
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        refresh();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
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
        int best = 0, BestNode;
        for (int i = 1; i <= n; i++) {
            int now = DP(i);
            if (now > best) {
                best = now;
                BestNode = i;
            }
        }
        printf("Case %d: %d\n", ++ks, BestNode);
    }
}
