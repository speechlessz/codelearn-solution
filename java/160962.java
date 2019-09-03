/**
 * Lời giải từ bạn (để địa chỉ mail nên không tiện - có thể là Long Phan)
 */

int sumOfTheOddNumbers(int n) {
    // 1 + (4^n - 1)/3

    int mod = 1000000007;
    long y = fastPow(3, mod - 2, mod);

    int x = fastPow(4, n, mod);
    if (x == 0) {
        x = mod;
    }
    x -= 1;

    return (int) ((1L + x * y) % mod);
}

static int fastPow(int base, int n, int mod) {
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

