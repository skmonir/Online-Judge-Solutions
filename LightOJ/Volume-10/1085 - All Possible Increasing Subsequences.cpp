#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 1e5 + 5;
const int INF = (int) 1e9 + 7;
const int MOD = (int) 1e9 + 7;

int a[N], b[N], BIT[N];
map <int, int> ID;

int addmod(int x) {
    if (x < 0) x += MOD;
    if (x > MOD) x -= MOD;
    return x;
}

void upd(int x, int v) {
    while (x < N) {
        BIT[x] += v;
        BIT[x] = addmod(BIT[x]);
        x += x & -x;
    }
}

int ask(int x) {
    int res = 0;
    while (x > 0) {
        res += BIT[x];
        res = addmod(res);
        x -= x & -x;
    }
    return res;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        ID.clear();
        mem(BIT, 0);
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b, b + n);
        for (int i = 0, ii = 1; i < n; i++) {
            if (ID[b[i]] == 0) ID[b[i]] = ++ii;
        }
        for (int i = 0; i < n; i++) {
            a[i] = ID[a[i]];
        }
        upd(1, 1);
        for (int i = 0; i < n; i++) {
            upd(a[i], ask(a[i] - 1));
        }
        printf("Case %d: %d\n", ++ks, addmod(ask(n + 3) - 1));
    }
    return 0;
}
