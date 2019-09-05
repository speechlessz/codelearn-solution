int maxLengthAverage(std::vector<int> a) {
    if (a.size() == 0) return 0;
    int maxV = a[0];
    for (int x: a) maxV = max(maxV, x);
    int res = 1;
    for (int i=0;i<a.size();i++) {
        if (a[i] == maxV) {
            int j = i;
            for (; j+1<a.size() && a[j+1]==maxV; j++) {}
            res = max(res, j-i+1);
            i = j;
        }
    }
    return res;
}
