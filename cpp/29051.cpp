typedef long long ll;
typedef vector<int> vi;

vi dec2bin(ll x) {
    vi res;
    for (;x>0;x/=2) res.push_back(x%2);
    reverse(res.begin(), res.end());
    return res;
}

long long maximumNumber(long long a, long long b) {
    vi u = dec2bin(a);
    vi v = dec2bin(b);
    if (u.size() == v.size()) {
        int i = 0;
        while (i < u.size() && u[i] == v[i]) i++;
        return (1ll << int(u.size()-i)) - 1;
    }
    return (1ll << int(v.size())) - 1;
}
