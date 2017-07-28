#include <bits/stdc++.h>

using namespace std;

#define endl           '\n'
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define mem(x, y)      memset(x, y, sizeof x)

template <typename T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <typename T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <typename T> inline void umax(T &a, T b) {a = a > b ? a : b;}

const int N = 6;
int MOD;


struct Matrix {
    int m[N][N];
    Matrix() {
        memset(m, 0, sizeof m);
    }
    Matrix Mul(Matrix a, Matrix b) {
        Matrix c = Matrix();
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < N; ++k) {
                for (int j = 0; j < N; ++j) {
                    c.m[i][j] = (c.m[i][j] + 1LL * a.m[i][k] * b.m[k][j]) % MOD;
                }
            }
        }
        return c;
    }
    Matrix Exp(Matrix base, int p) {
        if (p == 1) return base;
        Matrix Res = Exp(base, p >> 1);
        Res = Mul(Res, Res);
        if (p & 1) Res = Mul(base, Res);
        return Res;
    }
};

int main() {
    int tc, ks = 0;
    scanf("%d", &tc);
    while (tc--) {
        int a1, b1, c1, a2, b2, c2;
        int f0, f1, f2, g0, g1, g2;
        scanf("%d%d%d", &a1, &b1, &c1);
        scanf("%d%d%d", &a2, &b2, &c2);
        scanf("%d%d%d", &f0, &f1, &f2);
        scanf("%d%d%d", &g0, &g1, &g2);
        scanf("%d", &MOD);


        Matrix base = Matrix();
        base.m[0][0] = a1, base.m[0][1] = b1, base.m[0][5] = c1;
        base.m[3][3] = a2, base.m[3][4] = b2, base.m[3][2] = c2;
        base.m[1][0] = base.m[2][1] = base.m[4][3] = base.m[5][4] = 1;

        int q; scanf("%d", &q);
        printf("Case %d:\n", ++ks);
        while (q--) {
            int n, x, y; scanf("%d", &n);
            if (n <= 2) {
                if (n == 0) x = f0 % MOD, y = g0 % MOD;
                if (n == 1) x = f1 % MOD, y = g1 % MOD;
                if (n == 2) x = f2 % MOD, y = g2 % MOD;
                printf("%d %d\n", x, y); continue;
            }
            Matrix res = res.Exp(base, n - 2);
            x = (res.m[0][0] * f2 + res.m[0][1] * f1 + res.m[0][5] * g0) % MOD;
            x = (x + res.m[0][2] * f0 + res.m[0][3] * g2 + res.m[0][4] * g1) % MOD;
            y = (res.m[3][3] * g2 + res.m[3][4] * g1 + res.m[3][2] * f0) % MOD;
            y = (y + res.m[3][0] * f2 + res.m[3][1] * f1 + res.m[3][5] * g0) % MOD;
            printf("%d %d\n", x, y);
        }
    }
    return 0;
}
