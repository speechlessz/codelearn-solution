std::vector<std::vector<int>> numbersSquare(int n, int s)
{
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i=0;i<n;i++) {
        int r = 0, c = i;
        for (int j=0;j<2*i+1;j++) {
            a[r][c] = s++;
            if (r < i) r++; else c--;
        }
    }
    return a;
}
