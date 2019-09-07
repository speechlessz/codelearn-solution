typedef long long ll;

int numberSteps(int n, std::vector<int> a, int m) {
    unordered_map<ll, int> f;
    queue<int> q;
    f[n] = 1;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : a) {
            if ((ll)x + y <= m && !f[x + y]) {
                f[x + y] = f[x] + 1;
                q.push(x + y);
            }
            if ((ll)x * y <= m && !f[x * y]) {
                f[x * y] = f[x] + 1;
                q.push(x * y);
            }
        }
    }
    return f[m] - 1;
}