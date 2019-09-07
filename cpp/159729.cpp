bool isTwoSameSequences(std::vector<int> a)
{
    int n = a.size();
    for (int i=1;i<n;i++) a[i] += a[i-1];
    for (int i=0;i<n-1;i++) {
        if (a[i] == a[n-1] - a[i]) return true;
    }
    return false;
}
