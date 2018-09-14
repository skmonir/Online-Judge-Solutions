#include <bits/stdc++.h>

using namespace std;

int dp[12][12];
int n, m, a[12];

int call(int pos, int lastDigit) {
    if (pos > n) return 1;

    int &ret = dp[pos][lastDigit];

    if (~ret) return ret;

    ret = 0;

    for (int i = 1; i <= m; ++i) {
        if (abs(lastDigit - a[i]) <= 2) {
            ret += call(pos + 1, a[i]);
        }
    }

    return ret;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &m, &n);
        for (int i = 1; i <= m; ++i) {
            scanf("%d", a + i);
        }

        int res = 0;
        memset(dp, -1, sizeof dp);
        for (int i = 1; i <= m; ++i) {
            res += call(2, a[i]);
        }

        printf("Case %d: %d\n", ++ks, res);
    }

    return 0;
}
