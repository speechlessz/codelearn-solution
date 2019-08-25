typedef long long ll;

int playGame(int k, int n, int a, int b) {
    int l = 0, r = n, x = -1;
    while (l <= r) {
        int m = (l+r)>>1;
        if ((ll)k-(ll)a*m-(ll)b*(n-m) > 0) {
            x = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    return x;
}
