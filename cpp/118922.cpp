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

const int mod = 1e9 + 9;
ll f[50][500][500];

long long weights(int n, int m) {
    int s = n * (n + 1) / 2;
    int w = (s - m) / 2 + m;

    f[0][0][0] = 1ll;
    FOR(i, 1, n) {
        FOR(j, 0, w) {
            FOR(k, 0, w) {
                f[i][j][k] = f[i - 1][j][k];
                if (j >= i)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j - i][k]) % mod;
                if (k >= i)
                    f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - i]) % mod;
                // printf("%d %d %d = %d\n", i, j, k, f[i][j][k]);
            }
        }
    }

    ll res = 0ll;
    FOR(a, 0, (s - m) / 2) {
        int b = m + a;
        res = (res + f[n][a][b]) % mod;
    }
    return res;
}
