#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

const int mod = 1e9 + 7;
const int N = 1005;
ll gt[N], inv[N], f[N][2];
int n, m;

ll power(ll x, int n) {
    if (n == 0)
        return 1ll;
    ll t = power(x, n / 2);
    return (t * t % mod) * (n % 2 ? x : 1) % mod;
}

void init() {
    gt[0] = 1ll;
    FOR(i, 1, n) gt[i] = gt[i - 1] * i % mod;
    FOR(i, 0, n) inv[i] = power(gt[i], mod - 2);
}

int queueInPark(int n_, int m_) {
    n = n_;
    m = m_;
    init();

    FOR(i, 1, n) f[i][0] = gt[i - 1];
    FOR(j, 2, m) {
        ll tmp = f[j - 1][0] * inv[j - 1] % mod;
        FOR(i, j, n) {
            f[i][1] = gt[i - 1] * tmp % mod;
            tmp = (tmp + f[i][0] * inv[i] % mod) % mod;
        }
        FOR(i, j, n) f[i][0] = f[i][1];
    }

    return f[n][0];
}
