#include <bits/stdc++.h>
 
using namespace std;
 
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
 
 
const LL Mod = 1000000007;
const int N = 1e5 + 5;
 
 
int main() {
    int tc, ks = 0;
    cin >> tc;
    while (tc--) {
        printf("Case %d:\n", ++ks);
        int n, q;
        cin >> n >> q;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        while (q--) {
            int l, r;
            cin >> l >> r;
            int x = upper_bound(all(a), l) - a.begin();
            int y = upper_bound(all(a), r) - a.begin();
            if (x > 0 and a[x - 1] == l) y++;
            cout << y - x << endl;
        }
    }
}
