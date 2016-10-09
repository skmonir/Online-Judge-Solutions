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
int used[N], low[N], in[N], AP[N];
 
void dfs(int cur, int par = -1) {
    int son = 0;
    used[cur] = 1;
    low[cur] = in[cur] = ++timer;
    for (int i = 0; i < g[cur].size(); i++) {
        int to = g[cur][i];
        if (to == par) continue;
        if (used[to]) low[cur] = min(low[cur], in[to]);
        else {
            son++;
            dfs(to, cur);
            low[cur] = min(low[cur], low[to]);
            if (low[to] >= in[cur] && par != -1) AP[cur] = 1;
        }
    }
    if (son > 1 && par == -1) AP[cur] = 1;
}
 
int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
            used[i] = in[i] = 0;
            low[i] = AP[i] = 0;
        }
        int n, m;
        scanf("%d%d", &n, &m);
        timer = ans = 0;
        while (m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            if (!used[i]) dfs(i);
            ans += AP[i];
        }
        printf("Case %d: %d\n", ++ks, ans);
    }
}
