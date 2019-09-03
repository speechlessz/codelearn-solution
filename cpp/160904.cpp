typedef long long ll;

int sumOfOddNumbers(int n) {
    int mod = 1e9+7;
    ll res = 0ll;
    for (int i=1;i<=(1<<n);i++) {
        int j = i;
        for (;j%2==0;j/=2) {}
        res = (res + j) % mod;
    }
    return res;
}
