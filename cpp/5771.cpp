typedef long long ll;

int countSpanningTree(int n)
{
    int m = 1e9+7;
    ll res = 1ll;
    for (int i=1;i<=n-2;i++) res = (res * n) % m;
    return res;
}
