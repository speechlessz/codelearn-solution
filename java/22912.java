int sequenceFixing(String s)
{
    int t = 0, res = 0;
    for (char c: s.toCharArray()) {
        t += c == '(' ? 1 : -1;
        if (t < 0) {
            res++; t = 0;
        }
    }
    return res+t;
}

