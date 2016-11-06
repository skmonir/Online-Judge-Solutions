#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const int N = 25 + 5;

int d, n;
LL Mod, f[N];

struct Matrix {
    LL mat[N][N];
};

Matrix MatMul(Matrix A, Matrix B) {
    Matrix Res;
    fill(Res.mat, 0);
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            for (int k = 0; k < d; k++) {
                Res.mat[i][j] += (A.mat[i][k] % Mod * B.mat[k][j] % Mod) % Mod;
                Res.mat[i][j] %= Mod;
            }
        }
    }
    return Res;
}

Matrix MatExpo(Matrix Base, int p) {
    if (p == 1) return Base;
    Matrix Res = MatExpo(Base, p >> 1);
    Res = MatMul(Res, Res);
    if (p & 1) Res = MatMul(Base, Res);
    return Res;
}

int main() {
    while (scanf("%d%d%lld", &d, &n, &Mod) == 3) {
        if (d + n + Mod == 0) break;
        Matrix Base;
        fill(Base.mat, 0);
        for (int i = 0; i < d; i++) {
            scanf("%lld", &Base.mat[0][i]);
        }
        for (int i = 1; i < d; i++) {
            Base.mat[i][i - 1] = 1;
        }
        for (int i = d - 1; i >= 0; i--) {
            scanf("%lld", f + i);
        }
        LL ans = 0;
        if (n <= d) ans = f[d - n] % Mod;
        else {
            Matrix Res = MatExpo(Base, n - d);
            for (int i = 0; i < d; i++) {
                ans += (Res.mat[0][i] % Mod * f[i] % Mod) % Mod;
                ans %= Mod;
            }
        }
        printf("%lld\n", ans);
    }
}
