#include <bits/stdc++.h>
 
using namespace std;
 
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
 
const LL MOD = 1000000007;
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 31;
 
LL comb[N][N];
 
void combination() {
    comb[0][0] = 1;
    for (int i = 1; i < N; i++) {
        comb[i][0] = 1;
        for (int j = 1; j < N; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}
 
int main() {
    combination();
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("Case %d: ", ++ks);
        if (k > n) {
            printf("%d\n", 0);
            continue;
        }
        LL res = comb[n][k];
        for (LL i = n; k and i > 0; i--) res *= i, k--;
        printf("%lld\n", res);
    }
    return 0;
}
