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

int n, q, a[N];
int t[N << 2][3], f[N << 2];

void build(int nd, int s, int e) {
    if (s == e) {
        t[nd][0] = 1;
        return;
    }
    int md = (s + e) >> 1;
    build(nd << 1, s, md);
    build(nd << 1 | 1, md + 1, e);
    t[nd][0] = t[nd << 1][0] + t[nd << 1 | 1][0];
    t[nd][1] = t[nd << 1][1] + t[nd << 1 | 1][1];
    t[nd][2] = t[nd << 1][2] + t[nd << 1 | 1][2];
}

void upd(int nd, int s, int e, int l, int r) {
    if (f[nd]) {
        int x = t[nd][0], y = t[nd][1], z = t[nd][2];
        if (f[nd] == 1) {
            t[nd][0] = z, t[nd][1] = x, t[nd][2] = y;
        } else {
            t[nd][0] = y, t[nd][1] = z, t[nd][2] = x;
        }
        if (s != e) {
            f[nd << 1] = (f[nd << 1] + f[nd]) % 3;
            f[nd << 1 | 1] = (f[nd << 1 | 1] + f[nd]) % 3;
        }
        f[nd] = 0;
    }
    if (e < l or r < s) return;
    if (l <= s and r >= e) {
        int x = t[nd][0], y = t[nd][1], z = t[nd][2];
        t[nd][0] = z, t[nd][1] = x, t[nd][2] = y;
        if (s != e) {
            f[nd << 1] = (f[nd << 1] + 1) % 3;
            f[nd << 1 | 1] = (f[nd << 1 | 1] + 1) % 3;
        }
        return;
    }
    int md = (s + e) >> 1;
    upd(nd << 1, s, md, l, r);
    upd(nd << 1 | 1, md + 1, e, l, r);
    t[nd][0] = t[nd << 1][0] + t[nd << 1 | 1][0];
    t[nd][1] = t[nd << 1][1] + t[nd << 1 | 1][1];
    t[nd][2] = t[nd << 1][2] + t[nd << 1 | 1][2];
}

int ask(int nd, int s, int e, int l, int r) {
    if (f[nd]) {
        int x = t[nd][0], y = t[nd][1], z = t[nd][2];
        if (f[nd] == 1) {
            t[nd][0] = z, t[nd][1] = x, t[nd][2] = y;
        } else {
            t[nd][0] = y, t[nd][1] = z, t[nd][2] = x;
        }
        if (s != e) {
            f[nd << 1] = (f[nd << 1] + f[nd]) % 3;
            f[nd << 1 | 1] = (f[nd << 1 | 1] + f[nd]) % 3;
        }
        f[nd] = 0;
    }
    if (e < l or r < s) return 0;
    if (l <= s and r >= e) return t[nd][0];
    int md = (s + e) >> 1;
    int res = ask(nd << 1, s, md, l, r);
    res += ask(nd << 1 | 1, md + 1, e, l, r);
    return res;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        memset(t, 0, sizeof t);
        memset(f, 0, sizeof f);
        scanf("%d%d", &n, &q);

        printf("Case %d:\n", ++ks);

        build(1, 1, n);

        while (q--) {
            int x, l, r;
            scanf("%d%d%d", &x, &l, &r);
            x++, l++, r++;
            if (x == 1) upd(1, 1, n, l, r);
            else printf("%d\n", ask(1, 1, n, l, r));
        }
    }
    return 0;
}
