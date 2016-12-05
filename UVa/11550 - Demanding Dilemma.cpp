#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e2 + 5;

bool a[N][N], g[N][N];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n, m, f = 1;
        cin >> n >> m;
        fill(g, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int e = 1; e <= m; e++) {
            int c = 0, x = 0, y = 0;
            for (int v = 1; v <= n; v++) {
                if (!a[v][e]) continue;
                if (!c) x = v;
                else y = v;
                c++;
            }
            if (c != 2 || g[x][y]) f = 0;
            else g[x][y] = g[y][x] = 1;
        }
        puts(f ? "Yes" : "No");
    }
}
