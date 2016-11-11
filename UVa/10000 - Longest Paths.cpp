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
        used[u] = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].first;
            int cost = g[u][i].second;
            if (dis[v] < dis[u] + cost) {
                dis[v] = dis[u] + cost;
                if (!used[v]) {
                    pq.push(make_pair(dis[v], v));
                    used[v] = 1;
                }
            }
        }
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; i++) g[i].clear();
        int start; scanf("%d", &start);
        int x, y;
        while (scanf("%d%d", &x, &y) && x + y) {
            g[x].push_back(make_pair(y, 1));
        }
        SPFA(start);
        int best = 0, finish;
        for (int i = 1; i <= n; i++) {
            if (dis[i] > best) {
                best = dis[i];
                finish = i;
            }
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++ks, start, best, finish);
    }
}
