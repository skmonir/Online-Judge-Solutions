// Link : http://www.spoj.com/problems/COT/
// Key Idea : LCA + Persistent Segment Tree

#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = (int) 5e6 + 5;
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

vector <int> g[N];
map <int, int> FID, RID;
int n, m, dep[N], par[N][25];
int node, a[N], val[N], root[N], t[N][2];

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
    int cur = newNode(val[nd]);
    t[cur][0] = modify(t[nd][0], s, md, p);
    t[cur][1] = modify(t[nd][1], md + 1, e, p);
    val[cur] = val[t[cur][0]] + val[t[cur][1]];
    return cur;
}

int findKth(int und, int vnd, int lnd, int plnd, int s, int e, int k) {
    if (s == e) return RID[s];
    int md = s + e >> 1;
    int cnt = val[t[und][0]] + val[t[vnd][0]] - val[t[lnd][0]] - val[t[plnd][0]];
    if (cnt >= k) return findKth(t[und][0], t[vnd][0], t[lnd][0], t[plnd][0], s, md, k);
    else return findKth(t[und][1], t[vnd][1], t[lnd][1], t[plnd][1], md + 1, e, k - cnt);
}

void dfs(int u, int p) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    root[u] = modify(root[p], 1, n, FID[a[u]]);
    for (int i = 1; i <= 20; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) dfs(v, u);
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int dis = dep[a] - dep[b];
    for (int i = 20; i >= 0; i--) {
        if (dis & (1 << i)) a = par[a][i];
    }
    for (int i = 20; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i], b = par[b][i];
        }
    }
    return a == b ? a : par[a][0];
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        FID[a[i]];
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ii = 0;
    for (auto &i : FID) {
        i.second = ++ii;
        RID[ii] = i.first;
    }

    root[0] = newNode();
    Build(root[0], 1, n);
    dfs(1, 0);

    while (m--) {
        int u = read(), v = read(), k = read();
        int l = LCA(u, v);
        int res = findKth(root[u], root[v], root[l], root[par[l][0]], 1, n, k);
        printf("%d\n", res);
    }
    return 0;
}
