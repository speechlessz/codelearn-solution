typedef long long ll;

long long minCostRepairingCar(std::vector<int> a, std::vector<int> b) {
    int n = a.size();
    int cntMinA = 0;
    ll sum = 0ll;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            sum += a[i];
            cntMinA++;
        } else {
            sum += b[i];
        }
    }
    if (n == 1) return sum;
    if (cntMinA > 0 && cntMinA < n)
        return sum;
    ll res = (ll)1e9 * n;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i]) {
            res = min(res, sum - a[i] + b[i]);
        }
    }
    return res;
}
