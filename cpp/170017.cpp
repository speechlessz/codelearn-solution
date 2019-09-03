#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define EL printf("\n")
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

const int N = 2e5 + 5;
int n, x, a[N], b[N];

int deliverItems(std::vector<int> weights) {
    for (int x : weights) a[x]++;
    int res = 0;
    int m = 200001;
    FOR(i, 1, m) {
        if (a[i] > 0 && i > 1 && b[i - 1] == 0) {
            b[i - 1] = 1;
            a[i]--;
        }
        if (a[i] > 0 && b[i] == 0) {
            b[i] = 1;
            a[i]--;
        }
        if (a[i] > 0 && b[i + 1] == 0) {
            b[i + 1] = 1;
            a[i]--;
        }
    }
    FOR(i, 1, m) res += b[i] > 0;
    return res;
}
