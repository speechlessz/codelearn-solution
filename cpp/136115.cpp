int subtractNumber(int a, int b)
{
    if (a < b) swap(a,b);
    int res = 0;
    for (; b > 0;) {
        a -= b;
        res++;
        if (a < b) swap(a,b);
    }
    return res;
}
