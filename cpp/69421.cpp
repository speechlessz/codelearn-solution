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

std::vector<int> smallestSq(std::vector<int> a) {
    int n = sz(a);

    deque<int> res;
    unordered_map<int, bool> used;
    unordered_map<int, int> cnt;
    for (int x : a) cnt[x]++;
    int m = cnt.size();
    for (int x : a) {
#ifdef debug
        cout << x << ": ";
#endif
        while (!res.empty() && !used[x] && res.back() > x &&
               cnt.size() >= m - res.size() && cnt[res.back()] > 0) {
            used[res.back()] = 0;
            res.pop_back();
        }
        if (!used[x]) {
            res.push_back(x);
            used[x] = 1;
        }
        cnt[x]--;
        if (cnt[x] == 0)
            cnt.erase(x);
#ifdef debug
        for (int x : res) cout << x << " ";
        EL;
#endif
    }
    return vi(res.begin(), res.end());
}

#ifdef debug
int main() {

    smallestSq(vi({43, 41, 41, 1, 4, 4,  1,  50, 1,  43, 4,
                   43, 1,  13, 4, 4, 41, 50, 6,  50, 50}));

    EL;
    return 0;
}
#endif
