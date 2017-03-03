#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()

const LL MOD = 1000000007;
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 5e6 + 5;

int ks;

LL f(LL n) {
    LL m = n >> 1;
    return (n * (n + 1) / 2) - m * (m + 1);
}

void solve(LL k) {
    LL lo = 1, hi = (LL) 1e8;
    while (hi >= lo) {
        LL mid = (lo + hi) >> 1;
        if (f(mid) >= k) hi = mid - 1;
        else lo = mid + 1;
    }
    for (LL i = lo - (1 ^ (lo & 1)) - 2; i <= hi; i += 2) {
        if (f(i) >= k) {lo = i; break;}
    }
    LL n = (lo + 1) >> 1, x, y;
    LL rest = k - f(lo - 1);

    if (rest >= n) x = n, y = n - rest % n;
    else y = n, x = rest;

    if (n & 1) swap(x, y);

    printf("Case %d: %lld %lld\n", ++ks, x, y);
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        LL k; scanf("%lld", &k);
        solve(k);
    }
    return 0;
}
