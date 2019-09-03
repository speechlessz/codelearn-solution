// Lời giải từ bạn ChickenTapCode

long MinCostRepairingCar(int[] a, int[] b)
{
    long ret = 0;
    bool checka = false, checkb = false;
    int mincost = 1000000000;
    for(int i=0; i <a.Length; i++) {
        int min = Math.Min(a[i], b[i]);
        mincost = Math.Min(mincost, Math.Abs(a[i]- b[i]));
        if (min == a[i]) checka = true;
        if (min == b[i]) checkb = true;
        ret+= Math.Min(a[i], b[i]);
    }
    if (a.Length >1 && (!checka || !checkb)) ret+= mincost;
    return ret;
}
