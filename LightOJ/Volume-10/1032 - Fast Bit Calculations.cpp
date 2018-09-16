#include <bits/stdc++.h>

using namespace std;

int n, a[33];
long long dp[33][2][2][33];

long long call(int pos, int small, int last, int cnt) {
    if (pos > n) return cnt;

    long long &ret = dp[pos][small][last][cnt];

    if (~ret) return ret;

    ret = 0;

    int lim = small ? 1 : a[pos];
    for (int i = 0; i <= lim; ++i) {
        ret += call(pos + 1, small or i < a[pos], i, cnt + (i & last));
    }

    return ret;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        int x; scanf("%d", &x);
        n = 0;
        while (x > 0) {
            a[++n] = x % 2;
            x /= 2;
        }
        reverse(a + 1, a + n + 1);

        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n", ++ks, call(1, 0, 0, 0));
    }

    return 0;
}
