#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 15;

int n, m, b, curr;
int a[N], cnt[N], res[N];

struct data {
    int l, r, id;
    bool operator < (const data &x) const {
        return l / b == x.l / b ? r < x.r : l / b < x.l / b;
    }
} q[N];

void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) curr++;
}

void del(int x) {
    cnt[x]--;
    if (cnt[x] == 0) curr--;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        memset(cnt, 0, sizeof cnt);
        scanf("%d%d", &n, &m);
        b = sqrt(n);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].id = i;
        }
        curr = 0;
        sort(q + 1, q + m + 1);
        int L = 1, R = 0;
        printf("Case %d:\n", ++ks);
        for (int i = 1; i <= m; i++) {
            int l = q[i].l, r = q[i].r, id = q[i].id;
            while (L < l) del(a[L++]);
            while (L > l) add(a[--L]);
            while (R < r) add(a[++R]);
            while (R > r) del(a[R--]);
            res[id] = curr;
        }
        for (int i = 1; i <= m; i++) {
            printf("%d\n", res[i]);
        }
    }
    return 0;
}
