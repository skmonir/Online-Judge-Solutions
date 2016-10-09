#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const LL Mod = 1000000007;
const int N = 1e5 + 5;

map <string, vector <string> > g;
map <string, int> color;
int cycle, ks;

void dfs(string cur) {
    color[cur] = 1;
    for (int i = 0; i < g[cur].size(); i++) {
        string to = g[cur][i];
        if (color[to] == 0) dfs(to);
        if (color[to] == 1) cycle = 1;
    }
    color[cur] = 2;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        cycle = 0;
        g.clear();
        color.clear();
        set <string> node;
        set <string> :: iterator ii;
        int m;
        scanf("%d", &m);
        while (m--) {
            char s[11], t[11];
            scanf("%s%s", s, t);
            g[t].push_back(s);
            node.insert(s);
            node.insert(t);
        }
        for (ii = node.begin(); ii != node.end(); ii++) {
            if (!color[*ii] && !cycle) dfs(*ii);
        }
        printf("Case %d: ", ++ks);
        puts(cycle ? "No" : "Yes");
    }
}
