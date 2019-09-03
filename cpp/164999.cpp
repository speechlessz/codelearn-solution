long long deathPaths(long long n, int d, int m) {
    return n - (n/d + n/m - n/(d*m/__gcd(d,m)));
}
