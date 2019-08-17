#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

int pickCandies(std::vector<int> a) {
    int n = a.size();
    if (n == 0)
        return 0;
    int f[n];
    f[0] = a[0];
    f[1] = max(a[0], a[1]);
    FOR(i, 2, n - 1) { f[i] = max(f[i - 1], a[i] + f[i - 2]); }
    return f[n - 1];
}
