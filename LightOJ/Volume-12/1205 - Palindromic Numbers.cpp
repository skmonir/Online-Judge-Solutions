#include <bits/stdc++.h>

using namespace std;

int n, a[23];
long long dp[2][23][2][23][2];

long long call(int zr, int l, int small, int r, int big) {
    if (l > r) return small or !big;

    long long &ret = dp[zr][l][small][r][big];

    if (~ret) return ret;

    ret = 0;

    int from = zr ^ 1, to = small ? 9 : a[l];
    for (int i = from; i <= to; ++i) {
        ret += call(1, l + 1, small or i < a[l], r - 1, i > a[r] or (big and i == a[r]));
    }
    return ret;
}

long long calc(long long x) {
    if (x == 0) return 0;
    if (x < 10) return x;
    n = 0;
    while (x > 0) {
        a[++n] = x % 10;
        x = x / 10;
    }
    reverse(a + 1, a + n + 1);

    long long ret = 0;
    for (int i = 1; i < n; ++i) {
        memset(dp, -1, sizeof dp);
        ret += call(0, 1, 1, i, 0);
    }

    memset(dp, -1, sizeof dp);
    ret += call(0, 1, 0, n, 0);

    return ret;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        long long l, r; scanf("%lld %lld", &l, &r);
        if (l > r) swap(l, r);

        long long res = calc(r) - calc(l - 1);

        printf("Case %d: %lld\n", ++ks, res);
    }

    return 0;
}
