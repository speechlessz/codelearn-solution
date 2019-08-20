def sequenceFixing(s):
    t, res = 0, 0
    for c in s:
        t += 1 if c == '(' else -1
        if t < 0:
            res += 1
            t = 0
    return res+t
