#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)
#define faster ios_base::sync_with_stdio(false) && cin.tie(NULL)

// #define debug 1

const int BASE = 26;
const int M = 1e9 + 9;

ll power(ll x, ll n, int mod) {
    if (n == 0)
        return 1ll;
    ll t = power(x, n / 2, mod);
    if (n % 2)
        return t * t % mod * x % mod;
    return t * t % mod;
}

bool ok(string s, int m, int k) {
    int n = sz(s);
    int x = 0;
    FOR(i, 0, m - 1) {
        x = 1ll * x * BASE + (s[i] - 'a') % M;
    }
    unordered_map<int, int> c;
    c[x]++;
    int maxC = 1;
    int p = power(BASE, m - 1, M);
    FOR(i, m, n - 1) {
        x = ((x % p) * 1ll * BASE % M + (s[i] - 'a')) % M;
        c[x]++;
        maxC = max(maxC, c[x]);
    }
    return maxC >= k;
}

int dtksub(std::string s, int k) {
    int n = sz(s);
    int l = 1, r = n, x = 0;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (ok(s, m, k)) {
            x = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return x;
}

#ifdef debug
int main() {

    cout << dtksub("xxxxx", 2) << endl;
    cout << dtksub("abababab", 3) << endl;

    EL;
    return 0;
}
#endif