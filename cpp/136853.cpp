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

bool solve(string a, int l) {
    int n = sz(a);
    int m = n / l;
    FOR(i, 0, l - 1) {
        FOR(j, 1, m - 1) {
            if (a[i + j * l] != a[i])
                return false;
        }
    }
    return true;
}

int commonDivisor(string a, string b) {
    for (; sz(a) != sz(b);) {
        if (sz(a) < sz(b))
            swap(a, b);
        FOR(i, 0, sz(b) - 1) if (a[i] != b[i]) return 0;
        a = a.substr(sz(b));
    }
    FOR(i, 0, sz(a) - 1) if (a[i] != b[i]) return 0;
    int n = sz(a), res = 0;
    for (int l = 1; l * l <= n; l++) {
        if (n % l)
            continue;
        res += solve(a, l);
        if (n / l > l)
            res += solve(a, n / l);
    }
    return res;
}

#ifdef debug
int main() {

    cout << commonDivisor("abcdabcd", "abcdabcdabcdabcd");
    cout << commonDivisor("aaaaaa", "aaaaaaaaa");

    EL;
    return 0;
}
#endif
