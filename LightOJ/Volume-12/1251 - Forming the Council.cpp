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

int ks, used[N];
vector <int> g[N], nodes;

bool dfs(int cur) {
    if (used[cur]) return true;
    if (used[cur ^ 1]) return false;
    used[cur] = true;
    nodes.push_back(cur);
    for (int i = 0; i < g[cur].size(); i++) {
        if (!dfs(g[cur][i])) return false;
    }
    return true;
}

bool Two_SAT(int m) {
    for (int i = 1; i <= m; i++) {
        if (!used[i * 2] && !used[i * 2 + 1]) {
            nodes.clear();
            if (!dfs(i * 2)) {
                for (int i = 0; i < nodes.size(); i++) {
                    used[nodes[i]] = false;
                }
                if (!dfs(i * 2 + 1)) return false;
            }
        }
    }
    return true;
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i < N; i++) {
            g[i].clear();
            used[i] = false;
        }
        for (int i = 1; i <= n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            u = u > 0 ? u * 2 + 1 : u * -2;
            v = v > 0 ? v * 2 + 1 : v * -2;
            g[u ^ 1].push_back(v);
            g[v ^ 1].push_back(u);
        }
        printf("Case %d: ", ++ks);
        if (Two_SAT(m)) {
            vector <int> ans;
            for (int i = 1; i <= m; i++) {
                if (used[i * 2 + 1]) ans.push_back(i);
            }
            int sz = ans.size();
            printf("Yes\n%d", sz);
            for (int i = 0; i < sz; i++) {
                printf(" %d", ans[i]);
            }
        } else printf("No");
        puts("");
    }
}
