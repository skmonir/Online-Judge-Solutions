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
 
map <int, int> FID, RID;
int node, a[N], val[N], t[N][2], root[N];
 
int newNode(int v = 0) {
    ++node;
    val[node] = v, t[node][0] = t[node][1] = -1;
    return node;
}
 
void Build(int nd, int s, int e) {
    if (s == e) return;
    int md = s + e >> 1;
    t[nd][0] = newNode(), t[nd][1] = newNode();
    Build(t[nd][0], s, md);
    Build(t[nd][1], md + 1, e);
}
 
int upd(int nd, int s, int e, int p) {
    if (p < s or p > e) return nd;
    if (s == e) {
        int cur = newNode(1);
        return cur;
    }
    int md = s + e >> 1;
    int cur = newNode();
    t[cur][0] = upd(t[nd][0], s, md, p);
    t[cur][1] = upd(t[nd][1], md + 1, e, p);
    val[cur] = val[t[cur][0]] + val[t[cur][1]];
    return cur;
}
 
int ask(int nd2, int nd1, int s, int e, int k) {
    if (s == e) return s;
    int md = s + e >> 1;
    int cnt = val[t[nd2][0]] - val[t[nd1][0]];
    if (cnt >= k) return ask(t[nd2][0], t[nd1][0], s, md, k);
    else return ask(t[nd2][1], t[nd1][1], md + 1, e, k - cnt);
}
 
int main() {
    int n, m; scanf("%d %d", &n, &m);
    root[0] = newNode();
    Build(root[0], 1, n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        FID[a[i]];
    }
 
    int ii = 0;
    for (auto &i : FID) {
        i.second = ++ii;
        RID[ii] = i.first;
    }
 
    for (int i = 1; i <= n; i++) {
        root[i] = upd(root[i - 1], 1, n, FID[a[i]]);
    }
 
    while (m--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int res = ask(root[r], root[l - 1], 1, n, k);
        printf("%d\n", RID[res]);
    }
    return 0;
}
