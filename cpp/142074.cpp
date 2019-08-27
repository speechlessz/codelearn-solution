int examRush(int t, std::vector<int> tm)
{
    sort(tm.begin(), tm.end());
    int res = 0;
    for (int i=0; i<tm.size() && t>=tm[i]; res++, t-=tm[i++]) {} 
    return res;
}
