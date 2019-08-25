int biggestRemainer(std::vector<int> a)
{
    int n = a.size();
    if (n <= 1) return 0; 
    sort(a.begin(), a.end());
    int m = unique(a.begin(), a.end()) - a.begin();
    if (m <= 1) return 0; 
    return a[m-2] % a[m-1];
}

