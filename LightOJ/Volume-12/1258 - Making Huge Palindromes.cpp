/**
 *    +--+--+--++--++--In the name of ALLAH--++--++--+--+--+
 *
 *    author:  skmonir
 *    created: 14-Aug-2018 21:55:10
**/

#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define mod                 1000000007LL
#define len(x)              (int) x.size()
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

const int N = 2e6 + 7;
const int inf = 1e9 + 7;
const int p = 131;

int z[N];
char s[N];

void z_algo(string &s, int sz) {
    mem(z, 0);
    int R = 0, L = 0;
    for (int k = 1; s[k]; k++) {
        if (k > R) {
            L = R = k;
            while (s[R] && s[R] == s[R - L]) R++;
            z[k] = R - L, R--;
        } else {
            int kk = k - L;
            if (k + z[kk] <= R) z[k] = z[kk];
            else {
                L = k;
                while (s[R] && s[R] == s[R - L]) R++;
                z[k] = R - L, R--;
            }
        }
    }
}

int solve() {
    scanf("%s", s);
    int n = strlen(s);

    string t = "";
    ROF (i, n - 1, 0) t += s[i];
    t += '+';
    FOR (i, 0, n - 1) t += s[i];

    z_algo(t, n);

    vector <int> v;
    FOR (i, n + 1, 2 * n) v.push_back(z[i]);
    v.push_back(0);

    int add = 0;
    FOR (i, -1, n - 1) if (n - i - 1 == v[i + 1]) {
        return printf("%d\n", n + i + 1);
    }

    return 0;
}

int main() {
    int tests = 1, CaseNo = 0; scanf("%d", &tests);
    while (tests--) {
        printf("Case %d: ", ++CaseNo);
        solve();
    }
    return 0;
}
