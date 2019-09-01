bool checkerBoard(std::vector<std::vector<bool>> a)
{
    int n = a.size();
    for (int i=1;i<n;i++) {
        if (a[0][i] ^ a[0][i-1] == 0) return false;
        if (a[i][0] ^ a[i-1][0] == 0) return false;
    }
    for (int i=1;i<n;i++) {
        for (int j=1;j<n;j++) {
            if (a[i][j] ^ a[i-1][j] == 0) return false;
            if (a[i][j] ^ a[i][j-1] == 0) return false;
        }
    }
    return true;
}
