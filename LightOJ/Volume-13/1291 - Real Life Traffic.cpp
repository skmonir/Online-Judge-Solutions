#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e4 + 5;
int ks = 0, timer, ans;


vector <int> g[N];
set <int> t[N];
int low[N], in[N], mark[N];
set < pair <int, int> > bridge;

void dfs(int cur, int par = -1) {
    low[cur] = in[cur] = ++timer;
    for (int i = 0; i < g[cur].size(); i++) {
        int to = g[cur][i];
        if (to == par) continue;
        if (in[to]) low[cur] = min(low[cur], in[to]);
        else {
            dfs(to, cur);
            low[cur] = min(low[cur], low[to]);
            if (low[to] > in[cur]) {
                bridge.insert(make_pair(min(cur, to), max(cur, to)));
            }
        }
    }
}

void traverse(int x, int z) {
    mark[x] = z;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (bridge.find(make_pair(min(x, y), max(x, y))) != bridge.end()) {
            continue;
        }
        if (!mark[y]) traverse(y, z);
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            g[i].clear(); t[i].clear();
            mark[i] = in[i] = low[i] = 0;
        }
        bridge.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        timer = ans = 0;
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(0);
        int mrk = 0;
        for (int i = 0; i < n; i++) {
            if (!mark[i]) traverse(i, ++mrk);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                int x = mark[i];
                int y = mark[g[i][j]];
                if (x != y) {
                    t[x].insert(y);
                    t[y].insert(x);
                }
            }
        }
        for (int i = 1; i <= mrk; i++) {
            if (t[i].size() == 1) ans++;
        }
        printf("Case %d: %d\n", ++ks, (ans + 1) >> 1);
    }
}
