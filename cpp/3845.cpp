#include <bits/stdc++.h>

using namespace std;

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

struct matrix {
    int n, m;
    int c[5][5];
    void reset() { FOR(i, 0, n - 1) FOR(j, 0, m - 1) c[i][j] = 0; }
};

matrix operator*(const matrix &a, const matrix &b) {
    assert(a.m == b.n);
    matrix res{a.n, b.m};
    res.reset();
    FOR(i, 0, a.n - 1) FOR(j, 0, b.m - 1) FOR(k, 0, a.m - 1) {
        res.c[i][j] += a.c[i][k] * b.c[k][j];
        res.c[i][j] %= 10;
    }
    return res;
}

matrix power(matrix x, int n) {
    if (n == 1)
        return x;
    matrix t = power(x, n / 2);
    if (n % 2)
        return t * t * x;
    return t * t;
}

int sequenceElement(std::vector<int> a, int n) {
    if (n <= 4)
        return a[n];

    matrix f{5, 1};
    FOR(i, 0, 4) f.c[i][0] = a[4 - i];

    int c[5][5]{{1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 1, 0, 0},
                {0, 0, 0, 1, 0}};

    matrix x{5, 5};
    FOR(i, 0, 4) FOR(j, 0, 4) x.c[i][j] = c[i][j];

    matrix res = power(x, n - 4) * f;

    return res.c[0][0];
}
