#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)
 
const LL Mod = 1000000007;
const int N = 1e4 + 5;
int ks = 0, timer, ans;
 
 
int foo, sz;
vector <int> g[N];
int low[N], in[N], col[N];
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
 
void bi_color(int x) {
    sz++;
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (bridge.find(make_pair(min(x, y), max(x, y))) != bridge.end()) {
            continue;
        }
        if (col[y] && col[x] == col[y]) foo = 1;
        if (!col[y]) {
            col[y] = 3 - col[x];
            bi_color(y);
        }
    }
}
 
int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
            col[i] = in[i] = low[i] = 0;
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
        for (int i = 0; i < n; i++) {
            if (!in[i]) dfs(i);
        }
        for (int i = 0; i < n; i++) {
            if (!col[i]) {
                foo = sz = 0;
                col[i] = 1;
                bi_color(i);
                if (foo) ans += sz;
            }
        }
        printf("Case %d: %d\n", ++ks, ans);
    }
}
