typedef pair<int, int> ii;

int check(ii a, ii b, ii c) {
    if (a == b || b == c || a == c)
        return false;
    return (b.second - a.second) * (c.first - b.first) !=
           (b.first - a.first) * (c.second - b.second);
}

int countTriangles(vector<int> xpoints, vector<int> ypoints) {
    int n = xpoints.size();
    int res = 0;
    vector<ii> points;
    for (int i = 0; i < n; i++) points.push_back({xpoints[i], ypoints[i]});
    for (ii a : points)
        for (ii b : points)
            for (ii c : points) res += check(a, b, c);
    return res / 6;
}