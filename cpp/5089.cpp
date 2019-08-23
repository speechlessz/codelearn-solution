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

int treeBottom(std::string s) {
    int n = sz(s);
    int sum[n], md = 0;
    FOR(i, 0, n) sum[i] = 0;

    int cur = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            cur++;
        else if (s[i] == ')')
            cur--;
        else if ('0' <= s[i] && s[i] <= '9') {
            int v = s[i] - '0';
            for (; i + 1 < n; i++) {
                if ('0' <= s[i + 1] && s[i + 1] <= '9') {
                    v = v * 10 + (s[i + 1] - '0');
                } else {
                    break;
                }
            }
            sum[cur] += v;
        }
        md = max(md, cur);
    }

    return sum[md - 1];
}

#ifdef debug
int main() {

    cout << treeBottom(
        "(2 (7 (2 () ()) (6 (5 () ()) (11 () ()))) (5 () (9 (4 () ()) ())))");

    EL;
    return 0;
}
#endif
