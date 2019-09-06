long long countNumbersLoveMath(long long m, long long n, long long p) {
    return min(m, p) - max(0LL, p-n) + 1;
}
