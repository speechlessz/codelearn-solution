int SequenceFixing(string s)
{
    int t = 0, res = 0;
    foreach(char c in s) {
        t += c == '(' ? 1 : -1;
        if (t < 0) {
            res++; t = 0;
        }
    }
    return res+t;
}

