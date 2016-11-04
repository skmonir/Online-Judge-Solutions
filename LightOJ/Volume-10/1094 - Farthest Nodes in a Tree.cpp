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

int ks, dis[N], used[N];
vector < pair <int, int> > g[N];

void SPFA(int src) {
    priority_queue < pair <int, int> > pq;
    for (int i = 0; i < N; i++) {
        dis[i] = used[i] = 0;
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
                if (!used[v]) pq.push(make_pair(dis[v], v));
            }
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
        int best = 0, x, y;
        for (int i = 0; i < n; i++) {
            if (best < dis[i]) {
                best = dis[i];
                x = i;
            }
        }
        SPFA(x);
        best = 0;
        for (int i = 0; i < n; i++) {
            best = Max(best, dis[i]);
        }
        printf("Case %d: %d\n", ++ks, best);
    }
}
