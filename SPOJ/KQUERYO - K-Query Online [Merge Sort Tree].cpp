#include <bits/stdc++.h>
 
using namespace std;
 
#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)
 
template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}
 
const int N = (int) 3e4 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;
 
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while ('0' > ch or ch > '9') {
        if ('-' == ch) f = -1; ch = getchar();
    }
    while ('0' <= ch and ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();
    }
    return x * f;
}
 
int a[N];
vector <int> t[N << 2];
 
void Build(int nd, int s, int e) {
    if (s == e) {
        t[nd].push_back(a[s]);
        return;
    }
    int md = s + e >> 1;
    Build(nd << 1, s, md);
    Build(nd << 1 | 1, md + 1, e);
    t[nd].resize(t[nd << 1].size() + t[nd << 1 | 1].size());
    merge(all(t[nd << 1]), all(t[nd << 1 | 1]), t[nd].begin());
}
 
int ask(int nd, int s, int e, int l, int r, int k) {
    if (e < l or s > r) return 0;
    if (l <= s and r >= e) {
        return t[nd].end() - upper_bound(all(t[nd]), k);
    }
    int md = s + e >> 1;
    int c1 = ask(nd << 1, s, md, l, r, k);
    int c2 = ask(nd << 1 | 1, md + 1, e, l, r, k);
    return c1 + c2;
}
 
int main() {
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
 
    Build(1, 1, n);
 
    int res = 0;
    int m = read();
    while (m--) {
        int a = read(), b = read(), c = read();
        a ^= res, b ^= res, c ^= res;
        res = ask(1, 1, n, a, b, c);
        printf("%d\n", res);
    }
    return 0;
}
