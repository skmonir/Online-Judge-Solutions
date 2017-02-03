#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 500 + 5;


int n, m;
int dis[N], par[N];
vector < pair <int, int> > g[N];
bool used[N];

void SPFA(int s) {
    priority_queue < pair <int, int> > pq;
    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        used[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int w = max(g[u][i].second, dis[u]);
            if (!used[v] and w < dis[v]) {
                dis[v] = w;
                pq.push({ -dis[v], v});
            }
        }
    }
}

int main() {
    int tc, ks = 0; scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            g[i].clear();
            dis[i] = INT_MAX, used[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        int s; scanf("%d", &s);
        SPFA(s);
        printf("Case %d:\n", ++ks);
        for (int i = 0; i < n; i++) {
            if (dis[i] == INT_MAX) puts("Impossible");
            else printf("%d\n", dis[i]);
        }
    }
}
