from fractions import Fraction


def basicFractionProgram(n):
    if n <= 1:
        return n
    res = Fraction(0)
    for i in range(1, n+1):
        res = res + Fraction(1, i)
    return str(res.numerator) + "/" + str(res.denominator)
