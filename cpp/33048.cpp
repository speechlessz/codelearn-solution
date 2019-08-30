std::vector<std::string> chainNames(std::vector<std::string> a) {
    int n = a.size();
    int first[300], last[300];
    vector<string> b(a.begin(), a.end());
    for (int i=0;i<n;i++) {
        string &s = b[i];
        for (int j=0;j<s.size();j++) {
            if ('A' <= s[j] && s[j] <= 'Z') s[j] += 'a' - 'A';
        }
    }
    for (char c='a';c<='z';c++) first[c] = last[c] = -1;
    for (int i=0;i<n;i++) first[b[i][0]] = last[b[i].back()] = i;
    int sIdx = -1;
    for (int i=0;i<n;i++) {
        if (last[b[i][0]] == -1) {
            sIdx = i;
            break;
        }
    }
    vector<string> res;
    int j = sIdx;
    res.push_back(a[j]);
    while (res.size() < n) {
        j = first[b[j].back()];
        res.push_back(a[j]);
    }
    return res;
}
