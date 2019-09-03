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

std::vector<long long> queryOnPrimes(std::vector<int> lQueries, std::vector<int> rQueries) {
    vector<int> p = genPrimes(10000);
    vector<ll> res;
    for (int i = 0; i < lQueries.size(); i++) {
        int l = lQueries[i] - 1;
        int r = rQueries[i] - 1;
        ll v = p[l] * p[r] - p[(l + r + 1) / 2];
        res.push_back(v);
    }
    return res;
}
