int zigzagSequenceLength(std::vector<int> a)
{
    int n = a.size();
    int f[n+1][2];
    f[0][0] = 1;
    f[0][1] = 1;
    int res = 1;
    for (int i=1;i<n;i++) {
        f[i][0] = f[i][1] = 1;
        if (a[i] > a[i-1]) f[i][0] = f[i-1][1] + 1;
        else if (a[i] < a[i-1]) f[i][1] = f[i-1][0] + 1; 
        res = max(res, max(f[i][0], f[i][1]));
    }
    return res;
}

