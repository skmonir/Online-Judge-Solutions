#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()

const LL MOD = 1000000007;
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

int o, t;
int col[N];
bool taken[N];
vector <int> g[N];


void dfs(int u) {
    col[u] == 1 ? o++ : t++;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!col[v]) {
            col[v] = 3 - col[u];
            dfs(v);
        }
    }
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            col[i] = taken[i] = 0;
            g[i].clear();
        }
        vector <int> a;
        int n; scanf("%d", &n);
        while (n--) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
            if (!taken[u]) a.push_back(u);
            if (!taken[v]) a.push_back(v);
            taken[u] = taken[v] = 1;
        }
        int res = 0;
        for (int i = 0; i < a.size(); i++) {
            if (!col[a[i]]) {
                col[a[i]] = 1;
                o = t = 0;
                dfs(a[i]);
                res += max(o, t);
            }
        }
        printf("Case %d: %d\n", ++ks, res);
    }
    return 0;
}
