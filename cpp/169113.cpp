int fillingTheLake(int n) {
    vector<int> factor;
    unordered_map<int, int> cnt;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int c = 0;
            for (; n % i == 0; n /= i, c++) {}
            factor.push_back(i);
            cnt[i] = c;
        }
    }
    if (n > 1) {
        factor.push_back(n);
        cnt[n] = 1;
    }
    int res = 1ll;
    for (int x : factor) {
        res *= cnt[x]*3 + 1;
    }
    return res;
}
