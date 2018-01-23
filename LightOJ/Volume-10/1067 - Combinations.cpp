/**
 *    author:  skmonir
 *    created: 24-Jan-2018 00:09:26
**/

#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <TN T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <TN T, TN W> inline void Int(T &x, W &y) {Int(x), Int(y);}
template <TN T, TN W, TN Q> inline void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = 1e6 + 7;
const int inf = 1e9 + 7;
const int mod = 1e6 + 3;

long long f[N];

template <typename T, typename R>
T modpow(T base, R exp) {
    base %= mod;
    T res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

long long inv(long long n) {
    return modpow(n, mod - 2);
}

int main() {
    f[0] = 1;
    FOR (i, 1, N - 5) f[i] = (f[i - 1] * i) % mod;

    int tc, ks = 0;
    Int(tc);
    while (tc--) {
        int n, k; Int(n, k);

        long long u = f[n], d = inv(f[k] * f[n - k] % mod);
        long long res = u * d % mod;

        printf("Case %d: %lld\n", ++ks, res);
    }

    return 0;
}
