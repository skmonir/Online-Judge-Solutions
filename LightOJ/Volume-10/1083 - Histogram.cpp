#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 5;

void chkmax(int &a, int b) {a = a > b ? a : b;}


int MaxAreaOfHistogram(vector <int> &a, int n) {
    stack < pair <int, int> > st;
    st.push({0, 0});
    int best = 0;
    a[n + 1] = 1;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] > st.top().first) st.push({a[i], i});
        else {
            int ii = st.top().second;
            while (st.top().first >= a[i]) {
                chkmax(best, st.top().first * (i - st.top().second));
                ii = st.top().second;
                st.pop();
            }
            st.push({a[i], ii});
        }
    }
    return best;
}

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        int n; scanf("%d", &n);
        vector <int> a(n + 2);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        printf("Case %d: %d\n", ++ks, MaxAreaOfHistogram(a, n));
    }
    return 0;
}
