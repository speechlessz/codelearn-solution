#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define EL printf("\n")
#define sz(A) (int)A.size()
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

bool cmp(ii a, ii b) { return a.Y < b.Y; }

int maxArea(std::vector<int> a) {
    int n = a.size();

    vector<ii> b;
    for (int i = 0; i < n; i++)
        b.push_back({i, a[i]});

    sort(b.begin(), b.end(), cmp);

    int imax = b[n - 1].X, imin = b[n - 1].X;
    int res = 0;
    FOD(i, n - 2, 0) {
        res = max(res, b[i].Y * abs(imax - b[i].X));
        res = max(res, b[i].Y * abs(imin - b[i].X));
        imax = max(b[i].X, imax);
        imin = min(b[i].X, imin);
    }
    return res;
}
