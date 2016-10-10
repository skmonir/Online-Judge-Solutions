#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e4 + 5;
int ks = 0, timer;

vector <int> g[N];
vector < pair <int, int> > ans;
int used[N], low[N], in[N];

void dfs(int cur, int par = -1) {
    used[cur] = 1;
    low[cur] = in[cur] = ++timer;
    for (int i = 0; i < g[cur].size(); i++) {
        int to = g[cur][i];
        if (to == par) continue;
        if (used[to]) low[cur] = min(low[cur], in[to]);
        else {
            dfs(to, cur);
            low[cur] = min(low[cur], low[to]);
            if (low[to] > in[cur]) {
                ans.push_back(make_pair(min(cur, to), max(cur, to)));
            }
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        for (int i = 0; i < N; i++) {
            g[i].clear();
            used[i] = in[i] = low[i] = 0;
        }
        ans.clear();
        int k; scanf("%d", &k);
        timer = 0;
        for (int node = 0; node < k; node++) {
            int x, y;
            scanf("%d", &x);
            char s[100];
            scanf("%s", s);
            int n = 0;
            for (int i = 1; s[i]; i++) {
                if (s[i] != ')') n = n * 10 + s[i] - '0';
            }
            while (n--) {
                scanf("%d", &y);
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        for (int i = 0; i < k; i++) {
            if (!used[i]) dfs(i);
        }
        sort(all(ans));
        printf("Case %d:\n%d critical links\n", ++ks, ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d - %d\n", ans[i].first, ans[i].second);
        }
    }
}
