# Lời giải từ bạn kien_the_sun

def sumOfBigSequence(m, n):
    #a[0] = 1
    #a[1] = (m*m-m) // 2
    #a[2] = a[1] * (m**2) 
    #a[3] = a[2] * (m**2)
    #.....
    mod = 10 ** 9 + 7
    return (1 +(m*m - m) * 500000004 * (pow(m**2, n, mod)-1)* pow(m**2-1, mod-2, mod)) % mod