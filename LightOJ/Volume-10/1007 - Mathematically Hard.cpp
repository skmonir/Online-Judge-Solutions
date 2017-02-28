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
 
ULL phi[N];
bitset <N> isPrime;
 
void EulerPhi() {
    isPrime.set();
    for (int i = 1; i < N; i++) phi[i] = i;
    isPrime[1] = false, phi[1] = 0;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for (int j = i; j < N; j += i) {
                phi[j] *= i - 1;
                phi[j] /= i;
                isPrime[j] = false;
            }
        }
        phi[i] *= phi[i];
        phi[i] += phi[i - 1];
    }
}
 
int main() {
    EulerPhi();
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case %d: %llu\n", ++ks, phi[b] - phi[a - 1]);
    }
    return 0;
}
