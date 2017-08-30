#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <typename T>
inline void Int(T &x) {
    x = 0; int f = 1;
    register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) {
        if ('-' == ch) f = -1;
    }
    for (; isdigit(ch); ch = getchar()) {
        x = (x << 3) + (x << 1) + ch - '0';
    }
    x = x * f;
}

const int N = (int) 1e6 + 5;
const int INF = (int) 1e9 + 7;
const long long MOD = (long long) 1e9 + 7;

int n, m, node, a[N], last[N];
int root[N], val[N], t[N][2];

int newNode(int v = 0) {
    ++node;
    val[node] += v, t[node][0] = t[node][1] = -1;
    return node;
}

void Build(int nd, int s, int e) {
    if (s == e) return;
    int md = s + e >> 1;
    t[nd][0] = newNode(), t[nd][1] = newNode();
    Build(t[nd][0], s, md);
    Build(t[nd][1], md + 1, e);
}

int modify(int nd, int s, int e, int p) {
    if (p < s or p > e) return nd;
    if (s == e) {
        int cur = newNode(val[nd] + 1);
        return cur;
    }
    int md = s + e >> 1;
    int cur = newNode();
    t[cur][0] = modify(t[nd][0], s, md, p);
    t[cur][1] = modify(t[nd][1], md + 1, e, p);
    val[cur] = val[t[cur][0]] + val[t[cur][1]];
    return cur;
}

int ask(int nd1, int nd2, int s, int e, int l, int r) {
    if (e < l or s > r) return 0;
    if (s >= l and e <= r) return val[nd2] - val[nd1];
    int md = (s + e) >> 1;
    int c1 = ask(t[nd1][0], t[nd2][0], s, md, l, r);
    int c2 = ask(t[nd1][1], t[nd2][1], md + 1, e, l, r);
    return c1 + c2;
}

int main() {
    for (int i = 1; i < N; i++) last[i] = 1;

    Int(n); n++;
    root[1] = newNode();
    Build(root[1], 1, n);

    for (int i = 2; i <= n; i++) {
        Int(a[i]);
        root[i] = modify(root[i - 1], 1, n, last[a[i]]);
        last[a[i]] = i;
    }

    Int(m);
    while (m--) {
        int l, r;
        Int(l), Int(r); r++;
        int res = ask(root[l], root[r], 1, n, 1, l);
        printf("%d\n", res);
    }
    return 0;
}
