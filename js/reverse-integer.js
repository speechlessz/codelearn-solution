/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    let IMIN = -((1 << 31) >>> 0)
    let IMAX = -IMIN - 1
    let sign = x > 0 ? 1 : -1
    x *= sign // get absolute

    let res = 0
    for (; x > 0; x = Math.floor(x / 10)) {
        res = res * 10 + x % 10
        if (res > IMAX || res < IMIN) return 0
    }
    return res * sign;
};
