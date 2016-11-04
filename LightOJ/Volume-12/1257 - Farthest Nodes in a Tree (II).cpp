#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e5 + 5;

vector < pair <int, int> > g[N];
int ks, dis[N], used[N], par[N], ans[N], taken[N];

void SPFA(int src) {
    priority_queue < pair <int, int> > pq;
    for (int i = 0; i < N; i++) {
        dis[i] = used[i] = 0;
        par[i] = -1;
    }
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        used[u] = 1;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int cost = g[u][i].second;
            if (used[v]) continue;
            if (dis[v] < dis[u] + cost) {
                dis[v] = dis[u] + cost;
                par[v] = u;
                if (!used[v]) pq.push(make_pair(dis[v], v));
            }
        }
    }
}

void dfs(int cur, int cost, int p) {
    used[cur] = 1;
    ans[cur] = cost + ans[p];
    for (int i = 0; i < g[cur].size(); i++) {
        int u = g[cur][i].first;
        int c = g[cur][i].second;
        if (!used[u] && !taken[u]) {
            dfs(u, c, cur);
        }
    }
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) g[i].clear();
        int n; scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            g[x].push_back(make_pair(y, z));
            g[y].push_back(make_pair(x, z));
        }
        SPFA(0);
        int best = 0, start, finish;
        for (int i = 0; i < n; i++) {
            if (best < dis[i]) best = dis[i], start = i;
        }
        SPFA(start);
        best = 0;
        for (int i = 0; i < n; i++) {
            if (best < dis[i]) best = dis[i], finish = i;
        }
        for (int i = 0; i < N; i++) used[i] = taken[i] = 0;
        int node = finish;
        while (node != -1) {
            taken[node] = 1;
            ans[node] = Max(dis[node], best - dis[node]);
            node = par[node];
        }
        for (int i = 0; i < n; i++) {
            if (taken[i]) {
                for (int j = 0; j < g[i].size(); j++) {
                    int u = g[i][j].first;
                    int c = g[i][j].second;
                    if (!taken[u] && !used[u]) dfs(u, c, i);
                }
            }
        }
        printf("Case %d:\n", ++ks);
        for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    }
}
