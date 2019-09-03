int n, k;
vector<string> res;

int check(string s) {
    int res = 0;
    for (int i=0;i<int(s.size())-k+1;i++) {
        int ok = true;
        for (int j=i;j<=i+k-1;j++) {
            if (s[j] == 'B') {
                ok = false; break;
            }
        }
        res += ok;
    }
    return res;
}

void solve(string s) {
    if (check(s) > 1) return;
    if (s.size() == n) {
        if (check(s) == 1) res.push_back(s);
        return;
    }
    solve(s + "A");
    solve(s + "B");
}

std::vector<std::string> stringAB(int _n, int _k) {
    n = _n; k = _k;
    solve("");
    return res;
}
