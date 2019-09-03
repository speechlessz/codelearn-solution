/**
 * Lời giải từ bạn TIEU_MAN
 */

int waitingDays(int[] a)
{
    int n = a.length;
    Arrays.sort(a);
    int ans = 0;
    for(int i = n - 1; i > 0; i -= 2) ans += (a[i] - a[i - 1]);
    return ans;
}
