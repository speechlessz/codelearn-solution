typedef long long ll;

ll powx(int x, int n, int mod) {
    if (n == 0)
        return 1ll;
    ll t = powx(x, n / 2, mod);
    t = t * t % mod;
    return n % 2 ? t * x % mod : t;
}

int sumOfBigSequence(int m, int n) {
    int mod = 1e9 + 7;
    ll x = m * (m - 1) / 2;
    ll y = m * m - 1;
    ll res = (x * ((powx(y + 1, n, mod) - 1 + mod) % mod) % mod + y) % mod;
    res = res * powx(y, mod - 2, mod) % mod;
    return res;
}