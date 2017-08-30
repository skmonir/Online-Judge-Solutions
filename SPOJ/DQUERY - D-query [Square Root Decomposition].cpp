#include<bits/stdc++.h>
using namespace std;
#define LL             long long
#define F              first
#define S              second
#define pii            pair <int, int>
#define mii            map <int, int>
#define vii            vector <int>
#define vll            vector <LL>
#define pb             push_back
#define eb             emplace_back
#define em             emplace
#define End            return 0
#define endl           '\n'
#define in             freopen("in.txt", "r", stdin)
#define out            freopen("out.txt", "w", stdout)
#define all(x)         x.begin(), x.end()
#define asort(v)       sort(v.begin(), v.end())
#define dsort(v)       sort(v.begin(), v.end(), greater <int> ())
#define fill(a, b)     memset(a, b, sizeof a)
#define bitcount(a)    __builtin_popcount(a)
#define gcd(a, b)      __gcd(a, b)
 
const double eps = 1e-15;
const double pi = acos(-1.0);
const int inf = 1 << 30;
const LL Mod = 1000000007;
const int N = 3e4 + 5;
 
 
int a[N];
int block_size = 180;
int cnt[1000005];
int ans[200005];
int cur = 0;
pair < int, pair <int, int> > ques[200005];
 
 
bool cmp(pair < int, pair <int, int> > &x, pair < int, pair <int, int> > &y) {
    int block_x = x.S.F / block_size;
    int block_y = y.S.F / block_size;
    return block_x == block_y ? x.S.S < y.S.S : block_x < block_y;
}
 
void add(int x) {
    cnt[a[x]]++;
    if (cnt[a[x]] == 1) cur++;
}
 
void del(int x) {
    cnt[a[x]]--;
    if (cnt[a[x]] == 0) cur--;
}
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &ques[i].S.F, &ques[i].S.S);
        ques[i].S.F--, ques[i].S.S--, ques[i].F = i;
    }
 
    sort(ques, ques + q, cmp);
 
    int mo_left = 0;
    int mo_right = -1;
 
    for (int i = 0; i < q; i++) {
        int L = ques[i].S.F;
        int R = ques[i].S.S;
        while (mo_left < L) del(mo_left++);
        while (mo_left > L) add(--mo_left);
        while (mo_right < R) add(++mo_right);
        while (mo_right > R) del(mo_right--);
        ans[ques[i].F] = cur;
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
    End;
}
