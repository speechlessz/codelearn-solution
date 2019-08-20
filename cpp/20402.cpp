typedef long long ll;
int evenNumbers(int n, int p)
{
    ll t = 1ll << n;
    if (t > p) return -1;
    int x = p/t;
    if (x%2 == 0) x--;
    return int(t*x);
}

