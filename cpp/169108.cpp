int fillingTheLake(int n) {
    n = n*n*n;
    int res = 0;
    for (int i=1;i*i<=n;i++) {
        if (n%i == 0) {
            res++;
            if (n/i != i) res++;
        }
    }
    return res;
}
