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

const int mod = 1e9 + 7;

ll powx(ll x, int n) {
    if (n == 0)
        return 1ll;
    ll t = powx(x, n / 2);
    if (n % 2 == 0)
        return (t * t) % mod;
    return ((t * t) % mod * x) % mod;
}

int sumOfTheOddNumbers(int n) {
    return (powx(4, n) + 2) * powx(3, mod - 2) % mod;
}

#ifdef debug
int main() {

    EL;
    return 0;
}
#endif
