int swapToSort(std::vector<int> a)
{
    vector<int> b(a);
    sort(b.begin(), b.end());
    int diff = 0;
    for (int i=0;i<a.size();i++) diff += a[i] != b[i];
    return diff == 0 ? 0 : diff == 2 ? 1 : -1;
}
