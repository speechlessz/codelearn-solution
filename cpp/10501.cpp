typedef long long ll;

long long robotPath(int m, int n) {
    ll c[100][100];
    c[0][0] = 1ll;
    for (int j=1;j<=n+m-2;j++) {
        c[0][j] = c[j][j] = 1ll;
        for (int i=1;i<j;i++) c[i][j] = c[i][j-1] + c[i-1][j-1];
    }

    return c[n-1][n+m-2];
}
