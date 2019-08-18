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

struct dta {
    int team, score, remains;
    bool operator<(const dta &o) const {
        return score < o.score;
    }
};

const int N = 35;
int n, m[N][N];
vector<vi> initMap;
dta a[N];

void init() {
    FOR(i, 1, n) FOR(j, 1, n) m[i][j] = initMap[i - 1][j - 1];
    FOR(i, 1, n) {
        a[i] = {i, 0, 0};
        FOR(j, 1, n) {
            if (i != j && m[i][j] == 1) {
                a[i].score += 3;
            }
            if (i != j && m[i][j] == 2)
                a[i].remains++;
        }
    }
}

bool solve(int x) {
    init();
    FOR(y, 1, n) {
        if (m[x][y] == 2) {
            m[x][y] = 1;
            m[y][x] = 0;
            a[x].score += 3;
            a[x].remains--;
            a[y].remains--;
        }
    }
    assert(a[x].remains == 0);

    priority_queue<dta> st;
    FOR(i, 1, n) if (a[i].remains > 0) st.push(a[i]);

    while (!st.empty()) {
        dta t = st.top(); // currently highest score
        st.pop();
        int u = t.team;
        if (t.remains != a[u].remains || t.score != a[u].score) {
            // old data on heap
            continue;
        }
        FOR(v, 1, n) {
            if (a[v].remains == 0 || v == u)
                continue;
            if (m[v][u] == 2) {
                m[v][u] = 1;
                m[u][v] = 0;
                a[v].score += 3;
                a[v].remains--;
                a[u].remains--;
                if (a[v].remains)
                    st.push(a[v]);
                if (a[u].remains)
                    st.push(a[u]);
                break;
            }
        }
    }

    FOR(i, 1, n) if (a[i].score > a[x].score) return false;
    return true;
}

std::string championChance(std::vector<std::vector<int>> m) {
    n = sz(m);
    initMap = m;
    string res = "";
    FOR(i, 1, n) res.push_back(solve(i) + '0');
    return res;
}

#ifdef debug
int main() {

    return 0;
}
#endif
