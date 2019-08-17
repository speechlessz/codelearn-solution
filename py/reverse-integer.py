class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1 if x > 0 else -1
        x *= sign
        res = 0
        IMAX = (1<<31) - 1
        IMIN = -1<<31
        while x > 0:
            res = res*10 + x%10
            if res < IMIN or res > IMAX:
                return 0
            x = math.floor(x/10)
        return res * sign
