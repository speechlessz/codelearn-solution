int waitingDays(std::vector<int> a) {
    sort(a.begin(), a.end());
    int res = 0;
    for (int i=0;i<=a.size()-2;i+=2) res += a[i+1]-a[i];
    return res;
}
