#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e6 + 5;
const int INF = (int) 1e9 + 7;
const int MOD = (int) 1e9 + 7;

map <int, int> ID;
int q[N], l[N], r[N], BIT[N];

void upd(int x, int v) {
    while (x < N) BIT[x] += v, x += x & -x;
}

int ask(int x) {
    int res = 0;
    while (x > 0) res += BIT[x], x -= x & -x;
    return res;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        mem(BIT, 0);
        ID.clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", l + i, r + i);
            ID[l[i]] = ID[r[i]] = 0;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", q + i);
            ID[q[i]] = 0;
        }
        int ii = 0;
        map <int, int> :: iterator itr = ID.begin();
        for (; itr != ID.end(); itr++) itr -> second = ++ii;
        for (int i = 1; i <= n; i++) {
            l[i] = ID[l[i]], r[i] = ID[r[i]];
            upd(l[i], 1), upd(r[i] + 1, -1);
        }
        printf("Case %d:\n", ++ks);
        for (int i = 1; i <= m; i++) {
            q[i] = ID[q[i]];
            printf("%d\n", ask(q[i]));
        }
    }
    return 0;
}
