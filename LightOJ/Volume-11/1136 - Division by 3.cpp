/**
 *    author:  skmonir
 *    created: 25-Jan-2018 22:01:20
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

const int N = 1e5 + 7;
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;


int main() {
    int tc, ks = 0;
    Int(tc);
    while (tc--) {
        int a, b; Int(a, b);
        int res = b - a + 1;
        a--;
        int r = b / 3 + (b % 3 > 0);
        int l = a / 3 + (a % 3 > 0);
        res -= r - l;

        printf("Case %d: %d\n", ++ks, res);
    }
    return 0;
}
