typedef long long ll;

long long sumSubstrings(std::string s)
{
    const int mod = 1e9+7;
    int n = s.size();
    ll f[n], res = 0;
    res = f[0] = s[0] - '0';
    for (int i=1;i<n;i++) {
        int d = s[i] - '0';
        f[i] = (f[i-1] * 10 + d * i + d) % mod;
        res = (res + f[i]) % mod;
    }
    return res;
}
