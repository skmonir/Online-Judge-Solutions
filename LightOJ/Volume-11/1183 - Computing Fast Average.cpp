#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 5;

int t[N << 2], f[N << 2];

void propagate(int nd, int s, int e) {
    if (~f[nd]) {
        t[nd] = f[nd] * (e - s + 1);
        if (s != e) f[nd << 1] = f[nd << 1 | 1] = f[nd];
        f[nd] = -1;
    }
}

void upd(int nd, int s, int e, int l, int r, int v) {
    propagate(nd, s, e);
    if (e < l or r < s) return;
    if (l <= s and e <= r) {
        f[nd] = v;
        propagate(nd, s, e);
        return;
    }
    int md = (s + e) >> 1;
    upd(nd << 1, s, md, l, r, v);
    upd(nd << 1 | 1, md + 1, e, l, r, v);
    t[nd] = t[nd << 1] + t[nd << 1 | 1];
}

int ask(int nd, int s, int e, int l, int r) {
    propagate(nd, s, e);
    if (e < l or r < s) return 0;
    if (l <= s and e <= r) return t[nd];
    int md = (s + e) >> 1;
    int c1 = ask(nd << 1, s, md, l, r);
    int c2 = ask(nd << 1 | 1, md + 1, e, l, r);
    return c1 + c2;
}

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(t, 0, sizeof t);
        memset(f, -1, sizeof f);
        printf("Case %d:\n", ++ks);
        while (m--) {
            int cc, l, r, v;
            scanf("%d%d%d", &cc, &l, &r);
            l++, r++;
            if (cc > 1) {
                int num = ask(1, 1, n, l, r);
                int den = r - l + 1;
                int g = gcd(num, den);
                if (!(num % den)) printf("%d\n", num / den);
                else printf("%d/%d\n", num / g, den / g);
            } else {
                scanf("%d", &v);
                upd(1, 1, n, l, r, v);
            }
        }
    }
    return 0;
}
