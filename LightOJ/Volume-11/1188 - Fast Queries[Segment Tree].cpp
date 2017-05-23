#include <bits/stdc++.h>

using namespace std;

#define all(x)  x.begin(), x.end()

const int N = 1e5 + 5;

int prv[N], last[N];
vector <int> t[N << 2];

void build(int nd, int s, int e) {
    if (s == e) {
        t[nd].push_back(prv[s]);
        return;
    }
    int md = (s + e) >> 1;
    build(nd << 1, s, md);
    build(nd << 1 | 1, md + 1, e);
    merge(all(t[nd << 1]), all(t[nd << 1 | 1]), back_inserter(t[nd]));
}

int ask(int nd, int s, int e, int l, int r) {
    if (l > e or s > r) return 0;
    if (s >= l and r >= e) {
        return lower_bound(all(t[nd]), l) - t[nd].begin();
    }
    int md = (s + e) >> 1;
    return ask(nd << 1, s, md, l, r) + ask(nd << 1 | 1, md + 1, e, l , r);
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        memset(last, 0, sizeof last);
        for (int i = 1; i < N << 2; i++) t[i].clear();
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            prv[i] = last[x];
            last[x] = i;
        }

        build(1, 1, n);
        printf("Case %d:\n", ++ks);
        while (m--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", ask(1, 1, n, l, r));
        }
    }
    return 0;
}
