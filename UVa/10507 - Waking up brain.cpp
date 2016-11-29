#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e5 + 5;

char s[33];
vector <int> g[33];
int wake[33], year[33], cnt[33];

int main() {
    int n, m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i < 33; i++) {
            g[i].clear();
            wake[i] = year[i] = cnt[i] = 0;
        }
        scanf("%d%s", &m, s);
        queue <int> q;
        wake[s[0] - 'A' + 1] = 1, q.push(s[0] - 'A' + 1);
        wake[s[1] - 'A' + 1] = 1, q.push(s[1] - 'A' + 1);
        wake[s[2] - 'A' + 1] = 1, q.push(s[2] - 'A' + 1);
        set <char> nodes(s, s + 3);
        while (m--) {
            scanf("%s", s);
            nodes.insert(s[0]); nodes.insert(s[1]);
            g[s[0] - 'A' + 1].push_back(s[1] - 'A' + 1);
            g[s[1] - 'A' + 1].push_back(s[0] - 'A' + 1);
        }
        if (nodes.size() < n) {
            puts("THIS BRAIN NEVER WAKES UP");
            continue;
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto i : g[x]) {
                if (wake[i]) continue;
                cnt[i]++;
                if (cnt[i] == 3) {
                    year[i] = year[x] + 1;
                    wake[i] = 1, q.push(i);
                }
            }
        }
        int best = 0, foo = 1;
        for (auto u : nodes) {
            int i = u - 'A' + 1;
            if (!wake[i]) foo = 0;
            best = max(best, year[i]);
        }
        if (!foo) puts("THIS BRAIN NEVER WAKES UP");
        else printf("WAKE UP IN, %d, YEARS\n", best);
    }
}
