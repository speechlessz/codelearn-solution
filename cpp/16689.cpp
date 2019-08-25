int chipMoving(std::vector<std::vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();

    int f[n][m][2], inf = 1e9;
    f[0][0][0] = f[0][0][1] = 0;
    for (int i=1;i<n;i++) { // col j = 0, same column
        f[i][0][0] = f[i-1][0][0] + a[i][0];
        f[i][0][1] = inf;
    }
    for (int j=1;j<m;j++) { // row i = 0, same row
        f[0][j][1] = f[0][j-1][1] + a[0][j];
        f[0][j][0] = inf;
    }
    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) {
            f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1] + 10) + a[i][j];
            f[i][j][1] = min(f[i][j-1][1], f[i][j-1][0] + 10) + a[i][j];
        }
    }
    return min(f[n-1][m-1][0], f[n-1][m-1][1]);
}
