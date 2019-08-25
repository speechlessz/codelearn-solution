int goodPairs(int n, int m, int c)
{
    if (c == 0) return m+1 + n+1;
    int res = 0;
    for (int i=1;i*i<=c;i++) {
        if (c%i > 0) continue;
        int j = c/i;
        if (i <= n && j <= m) {
            res++;
        }
        if (i < j) {
            if (j <= n && i <= m) res++;
        }
    }
    return res;
}

