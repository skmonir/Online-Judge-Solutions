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

int a[N], mx[N << 2];
int c[N << 2][2], t[N << 2][2];

void build(int nd, int s, int e) {
    if (s == e) {
        t[nd][0] = t[nd][1] = a[s];
        c[nd][0] = c[nd][1] = 1;
        mx[nd] = 1;
        return;
    }
    int md = (s + e) >> 1;
    build(nd << 1, s, md);
    build(nd << 1 | 1, md + 1, e);
    mx[nd] = max(mx[nd << 1], mx[nd << 1 | 1]);
    t[nd][0] = t[nd << 1][0], t[nd][1] = t[nd << 1 | 1][1];
    c[nd][0] = c[nd << 1][0], c[nd][1] = c[nd << 1 | 1][1];
    if (t[nd << 1][1] == t[nd << 1 | 1][0]) {
        mx[nd] = max(mx[nd], c[nd << 1][1] + c[nd << 1 | 1][0]);
        if (t[nd << 1][0] == t[nd << 1][1] and md - s + 1 == c[nd << 1][0]) {
            c[nd][0] = c[nd << 1][0] + c[nd << 1 | 1][0];
        }
        if (t[nd << 1 | 1][0] == t[nd << 1 | 1][1] and e - md == c[nd << 1 | 1][1]) {
            c[nd][1] = c[nd << 1][1] + c[nd << 1 | 1][1];
        }
    }
}

struct node {
    int mx, t0, t1, c0, c1;
    node(int _mx, int _t0, int _t1, int _c0, int _c1) {
        mx = _mx, t0 = _t0, t1 = _t1, c0 = _c0, c1 = _c1;
    }
};

node ask(int nd, int s, int e, int l, int r) {
    if (e < l or r < s) return {0, 0, 0, 0, 0};
    if (l <= s and r >= e) {
        return {mx[nd], t[nd][0], t[nd][1], c[nd][0], c[nd][1]};
    }
    int md = (s + e) >> 1;
    node lf = ask(nd << 1, s, md, l, r);
    node rg = ask(nd << 1 | 1, md + 1, e, l, r);
    int res = max(lf.mx, rg.mx);
    int cc0 = lf.c0, cc1 = rg.c1;
    if (lf.t1 == rg.t0) {
        res = max(res, lf.c1 + rg.c0);
        if (lf.t0 == lf.t1 and md - s + 1 == lf.c0) cc0 = lf.c0 + rg.c0;
        if (rg.t0 == rg.t1 and e - md == rg.c1) cc1 = lf.c1 + rg.c1;
    }
    return {res, lf.t0, rg.t1, cc0, cc1};
}

int main() {
    int tc, ks = 0; scanf("%d", &tc);
    while (tc--) {
        int n, c, q;
        scanf("%d%d%d", &n, &c, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
        }
        build(1, 1, n);
        printf("Case %d:\n", ++ks);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            node res = ask(1, 1, n, l, r);
            printf("%d\n", res.mx);
        }
    }
    return 0;
}
