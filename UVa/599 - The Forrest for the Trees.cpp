#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e5 + 5;

char s[123];
vector <int> g[33];
int used[33], sz[33];

bool dfs(int cur, int par = -1) {
    used[cur] = sz[cur] = 1;
    for (int i = 0; i < g[cur].size(); i++) {
        int u = g[cur][i];
        if (u == par) continue;
        if (used[u]) return false;
        dfs(u, cur);
        sz[cur] += sz[u];
    }
    return true;
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < 33; i++) {
            g[i].clear(); used[i] = sz[i] = 0;
        }
        while (scanf("%s", s)) {
            if (s[0] == '*') break;
            int u = s[1] - 'A' + 1;
            int v = s[3] - 'A' + 1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        scanf("%s", s);
        int len = strlen(s), tree = 0, acorn = 0;
        for (int i = 0; i < len; i += 2) {
            int u = s[i] - 'A' + 1;
            if (used[u]) continue;
            if (dfs(u)) {
                if (sz[u] == 1) acorn++;
                else tree++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
    }
}
