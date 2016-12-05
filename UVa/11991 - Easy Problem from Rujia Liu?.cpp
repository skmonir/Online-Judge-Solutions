#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e6 + 5;

vector <int> sz[N];

int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < N; i++) sz[i].clear();
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            sz[k].push_back(i + 1);
        }
        while (m--) {
            int k, v, ps;
            cin >> k >> v;
            if ((int) sz[v].size() < k) ps = 0;
            else ps = sz[v][k - 1];
            cout << ps << endl;
        }
    }
}
