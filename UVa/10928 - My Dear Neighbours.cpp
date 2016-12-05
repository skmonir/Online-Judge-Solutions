#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1e3 + 5;

vector <int> sz[N];

int main() {
    int tc; cin >> tc;
    while (tc--) {
        for (int i = 0; i < N; i++) sz[i].clear();
        int k, best = INT_MAX;
        cin >> k;
        cin.ignore();
        for (int i = 1; i <= k; i++) {
            int n, neighbour = 0;
            string s; getline(cin, s);
            istringstream iss(s);
            while (iss >> n) neighbour++;
            best = min(best, neighbour);
            sz[neighbour].push_back(i);
        }
        for (int i = 0; i < sz[best].size(); i++) {
            if (i > 0) cout << ' ';
            cout << sz[best][i];
        }
        cout << endl;
    }
}
