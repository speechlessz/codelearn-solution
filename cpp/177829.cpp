typedef long long ll;

#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, r, l) for (int i = r; i >= l; i--)

const int N = 1e5 + 5;
int t[N]; // binary index tree

ll get(int x) {
    ll res = 0ll;
    for (; x > 0; x -= x & -x) res += (ll)t[x];
    return res;
}

void upd(int x, int v) {
    for (; x < N; x += x & -x) t[x] += v;
}

long long sofaShipping(std::vector<int> a) {
    int n = a.size();
    ll res = 0ll;

    unordered_map<int, int> mp;
    vector<int> b(a);
    sort(b.begin(), b.end());
    FOR(i, 0, n - 1) mp[b[i]] = i + 1;

    FOR(i, 0, n - 1) {
        int x = mp[a[i]];
        res += (ll)(i + 1) - get(x);
        upd(x, 1);
    }
    return res;
}
