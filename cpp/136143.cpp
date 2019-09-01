int removeBit(int n) {
    int res = n >> 1;
    for (int i = 1, x = n; x > 1; x >>= 1, i++) {
        int m = ((n >> i) << (i - 1)) | (n & ((1 << i) - 1));
        res = max(res, m);
    }
    return res;
}