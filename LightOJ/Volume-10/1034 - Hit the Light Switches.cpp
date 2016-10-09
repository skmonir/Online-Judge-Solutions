#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;

int ks;
bool used[N];
vector <int> g[N];
vector <int> order;

void dfs(int cur) {
    used[cur] = 1;
    for (int i = 0; i < g[cur].size(); i++) {
        int to = g[cur][i];
        if (!used[to]) dfs(to);
    }
    order.push_back(cur);
}

void refresh() {
    for (int i = 0; i < N; i++) {
        g[i].clear();
        used[i] = false;
    }
    order.clear();
}

int main() {
    int tc;
    scanf("%d", &tc);
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
            if (!used[i]) dfs(i);
        }
        int ans = 0;
        fill(used, false);
        int sz = order.size();
        for (int i = sz - 1; i >= 0; i--) {
            int now = order[i];
            if (!used[now]) dfs(now), ans++;
        }
        printf("Case %d: %d\n", ++ks, ans);
    }
}
