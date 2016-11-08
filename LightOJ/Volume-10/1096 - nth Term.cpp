#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const int N = 25 + 5;
const int Mod = 10007;

int ks, f[5];
int n, a, b, c;

struct Matrix {
    LL mat[N][N];
};

Matrix MatMul(Matrix A, Matrix B) {
    Matrix Res;
    fill(Res.mat, 0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
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
    int tc; scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d%d", &n, &a, &b, &c);
        printf("Case %d: ", ++ks);
        if (n < 3) {
            puts("0");
            continue;
        }
        a %= Mod, b %= Mod, c %= Mod;
        Matrix Base;
        fill(Base.mat, 0);
        Base.mat[0][0] = a, Base.mat[0][2] = b, Base.mat[0][3] = 1;
        Base.mat[1][0] = Base.mat[2][1] = Base.mat[3][3] = 1;
        Matrix Res = MatExpo(Base, n - 2);
        int ans = Res.mat[0][3] * c;
        printf("%d\n", ans % Mod);
    }
}
