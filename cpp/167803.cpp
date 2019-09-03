int goldenAreas(std::vector<std::vector<int>> a) {
    int n = a.size();
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 2; j++) {
            int det = a[i][j] * a[i + 1][j + 1] - a[i + 1][j] * a[i][j + 1];
            res += det != 0;
        }
    }
    return res;
}
