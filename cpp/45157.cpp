int n, m, res;
std::vector<std::vector<int>> a, dd;

int dx[] { 0,0,1,-1 };
int dy[] { 1,-1,0,0 };

void dfs(int i, int j, int &c) {
    c++;
    dd[i][j] = 1;
    for (int k=0;k<4;k++) {
        int ii = i+dx[k];
        int jj = j+dy[k];
        if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
        if (dd[ii][jj] || a[i][j] != a[ii][jj]) continue;
        dfs(ii,jj,c);
    }
}

int largestPlateau(std::vector<std::vector<int>> map) {
    a = map;
    n = a.size();
    m = a[0].size();

    dd = a;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            dd[i][j] = 0;
        }
    }

    res = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!dd[i][j]) {
                int c = 0;
                dfs(i,j,c);
                res = max(res, c);
            }
        }
    }
    return res;
}
