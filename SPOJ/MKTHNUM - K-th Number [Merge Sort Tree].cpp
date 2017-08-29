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
const long long MOD = (long long) 1e9 + 7;
 
int a[N], pos[N];
vector <int> t[N << 2];
 
inline bool cmp(int x, int y) {
    return a[x] < a[y];
}
 
void build(int nd, int s, int e) {
    if (s == e) {
        t[nd].push_back(pos[s]);
        return;
    }
    int mid = (s + e) >> 1;
    build(nd << 1, s, mid);
    build(nd << 1 | 1, mid + 1, e);
    t[nd].resize(t[nd << 1].size() + t[nd << 1 | 1].size());
    merge(all(t[nd << 1]), all(t[nd << 1 | 1]), t[nd].begin());
}
 
int ask(int nd, int s, int e, int l, int r, int k) {
    if (s == e) return t[nd][0];
    int x = lower_bound(all(t[nd << 1]), l) - t[nd << 1].begin();
    int y = upper_bound(all(t[nd << 1]), r) - t[nd << 1].begin();
    int mid = (s + e) >> 1;
    if (k <= y - x) {
        return ask(nd << 1, s, mid, l, r, k);
    } else {
        return ask(nd << 1 | 1, mid + 1, e, l, r, k + x - y);
    }
}
 
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pos[i] = i;
    }
    sort(pos + 1, pos + n + 1, cmp);
    build(1, 1, n);
    while (m--) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", a[ask(1, 1, n, l, r, k)]);
    }
    return 0;
} 
