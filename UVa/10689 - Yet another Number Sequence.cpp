#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const int N = 1e5 + 5;

int Mod;
int mm[5] = {0, 10, 100, 1000, 10000};

struct Matrix {
    int mat[2][2];
};

Matrix MatMul(Matrix A, Matrix B) {
    Matrix Res;
    fill(Res.mat, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                Res.mat[i][j] += A.mat[i][k] * B.mat[k][j];
                Res.mat[i][j] %= Mod;
            }
        }
    }
    return Res;
}

Matrix MatExpo(Matrix Base, int p) {
    if (p == 1) return Base;
    if (p & 1) {
        return MatMul(Base, MatExpo(Base, p - 1));
    } else {
        Matrix Res = MatExpo(Base, p >> 1);
        return MatMul(Res, Res);
    }
}

int main() {
    int tc; scanf("%d", &tc);
    while (tc--) {
        int a, b, n, m;
        scanf("%d%d%d%d", &a, &b, &n, &m);
        Mod = mm[m], n++;
        Matrix Base;
        Base.mat[0][0] = 1, Base.mat[0][1] = 1;
        Base.mat[1][0] = 1, Base.mat[1][1] = 0;
        int ans;
        if (n == 1) ans = a % Mod;
        else if (n == 2) ans = b % Mod;
        else {
            Matrix Res = MatExpo(Base, n - 2);
            ans = (Res.mat[0][0] * b + Res.mat[0][1] * a) % Mod;
        }
        printf("%d\n", ans);
    }
}
