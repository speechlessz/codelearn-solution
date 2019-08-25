int chartFix(std::vector<int> a) {
    int n = a.size();
    vector<int> f(n+1,0);
    f[1] = 0;  // len 1, posistion 0
    int k = 1; // current max length 1
    for (int i=1;i<n;i++) {
        int l = 1, r = k, x = 0;
        while (l <= r) {
            int m = (l+r)>>1;
            if (a[i] > a[f[m]]) {
                x = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        if (x == k) {
            f[++k] = i;
        }
        if (a[i] < a[f[x+1]]) f[x+1] = i;
    }
    return n-k;
}
