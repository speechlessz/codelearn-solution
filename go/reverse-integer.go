func reverse(x int) int {
    IMAX := (1<<31) - 1
    IMIN := -1<<31
    sign := 1
    if x < 0 {
        sign = -1
    }
    x *= sign
    res := 0
    for x > 0 {
        res = res*10 + x%10
        if res < IMIN || res > IMAX {
            return 0
        }
        x /= 10
    }
    return res * sign
}
