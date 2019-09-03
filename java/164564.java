/** Lời giải từ bạn Long Phan */

int sumOfBigSequence(int m, int n) {
    /**
        u0 = 1 + .. + (m - 1)
        q = m^2
        s = 1 + u0 * (q^n - 1) / (q - 1)
    */

    long u0 = (long) (m * (m - 1) / 2);
    int q = m * m;
    int mod = 1000000007;

    int x = fastPow(q, n, mod);
    long y = fastPow(q - 1, mod - 2, mod);

    if (x == 0) {
        x = mod;
    }
    x -= 1;

    x = (int) ((u0 * x) % mod);

    return (int) ((1L + x * y) % mod);    
}

int fastPow(int base, int n, int mod) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return base;
    }

    long halfNext = fastPow(base, n / 2, mod);
    if (n % 2 == 0) {
        return (int) ((halfNext * halfNext) % mod);
    } else {
        return (int) ((((halfNext * halfNext) % mod) * base) % mod);
    }
}