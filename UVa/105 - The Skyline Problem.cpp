#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()

const LL MOD = 1000000007;
const LL LINF = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

struct data {
    int x, y, s;
    data(int _x, int _y, int _s) {
        x = _x, y = _y, s = _s;
    }
    bool operator < (const data &p) const {
        if (x != p.x) return x < p.x;
        if (s and p.s) return y > p.y;
        if (!s and !p.s) return y < p.y;
        return s and !p.s;
    }
};

vector <data> v;
multiset <int> ms;
vector < pair <int, int> > res;

int main() {
    int l, r, h;
    while (scanf("%d%d%d", &l, &h, &r) != EOF) {
        v.push_back({l, h, 1});
        v.push_back({r, h, 0});
    }
    sort(all(v));

    ms.insert(0);
    int curr = 0, n = (int) v.size();
    for (int i = 0; i < n; i++) {
        int h = v[i].y, x = v[i].x, s = v[i].s;
        if (s == 1) {
            ms.insert(h);
            if (curr != *ms.rbegin()) {
                res.push_back({x, h});
            }
        } else {
            ms.erase(ms.find(h));
            if (curr != *ms.rbegin()) {
                res.push_back({x, *ms.rbegin()});
            }
        }
        curr = *ms.rbegin();
    }
    int sz = res.size();
    for (int i = 0; i < sz; i++) {
        if (i) putchar(' ');
        printf("%d %d", res[i].first, res[i].second);
    }
    printf("\n");
    return 0;
}
