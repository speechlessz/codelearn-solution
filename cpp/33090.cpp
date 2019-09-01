std::vector<int> linearTimeSort(std::vector<int> arr)
{
    unordered_map<int,int> cnt;
    for (int x: arr) cnt[x]++;
    vector<int> res;
    for (int i=0;i<=arr.size();i++) {
        for (int j=1;j<=cnt[i];j++) {
            res.push_back(i);
        }
    }
    return res;
}
