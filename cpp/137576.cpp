int minMove(int n) {
    if (n == 1)
        return 0;
    int res = n - 1;
    for (int i = 2; i < n - 1; i++) {
        int ans = 0;
        int a = n, b = i;
        for (;;) {
            if (a == 1 && b == 1)
                break;
            ans++;
            if (ans >= res)
                break;
            a -= b;
            if (a < b)
                swap(a, b);
        }
        res = min(res, ans);
    }
    return res;
}
