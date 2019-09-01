bool pairOfShoes(std::vector<std::vector<int>> shoes)
{
    vector<int> a[2];
    for (auto s: shoes) {
        a[s[0]].push_back(s[1]);
    }
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    if (a[0].size() != a[1].size()) return false;
    for (int i=0;i<a[0].size();i++) {
        if (a[0][i] != a[1][i]) return false;
    }
    return true;
}
