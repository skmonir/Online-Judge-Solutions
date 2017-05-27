#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 2e5 + 5;
const int INF = (int) 1e9 + 7;
const int MOD = (int) 1e9 + 7;

int a[N], BIT[N];

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
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            upd(i, 1);
        }
        printf("Case %d:\n", ++ks);
        while (m--) {
            static char t[10];
            int x;
            scanf("%s%d", t, &x);
            if (t[0] == 'c') {
                int l = 1, r = n, f = -1;
                while (l <= r) {
                    int m = (l + r) >> 1;
                    int id = ask(m);
                    if (id == x) f = m, r = m - 1;
                    else if (id > x) r = m - 1;
                    else l = m + 1;
                }
                if (~f) {
                    upd(f, -1);
                    printf("%d\n", a[f]);
                } else puts("none");
            } else {
                a[++n] = x;
                upd(n, 1);
            }
        }
    }
    return 0;
}
