typedef long long ll;

vector<int> genPrimes(int maxN) {
    vector<int> primes;
    unordered_map<int, int> dd;
    for (int i = 2; i <= maxN; i++) {
        if (!dd[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= maxN; j += i) dd[j] = 1;
        }
    }
    return primes;
}

std::vector<int> queryOnPrimes(std::vector<int> lQueries, std::vector<int> rQueries) {
    int mod = 1e9 + 9;
    vector<int> p = genPrimes(10000);
    vector<int> res;
    for (int i = 0; i < lQueries.size(); i++) {
        int l = lQueries[i] - 1;
        int r = rQueries[i] - 1;
        ll v = 0ll;
        for (int j = l; j <= r; j++) v = (v + (ll)p[j] * p[j]) % mod;
        res.push_back(v);
    }
    return res;
}
