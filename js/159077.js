function isValidPassword(s){
    let n = s.length;
    if (n < 6 || n > 12) return false;
    let ca = 0, cA = 0, c0 = 0, cc = 0;
    for (let i=0;i<n;i++) {
        let c = s[i];
        ca += 'a' <= c && c <= 'z';
        cA += 'A' <= c && c <= 'Z';
        c0 += '0' <= c && c <= '9';
        cc += '!@#$%^&*()'.indexOf(c) > -1;
    }
    if (ca < 1 || ca > 4) return false;
    if (cA < 1 || cA > 4) return false;
    if (c0 < 1 || c0 > 4) return false;
    if (cc != 1) return false;
    if (ca+cA+c0+cc != n) return false;
    const nok = (i, l, r) => {
        if (l <= s[i] && s[i] <= r) {
            if (l <= s[i+1] && s[i+1] <= r) {
                if (l <= s[i+2] && s[i+2] <= r) {
                    return true;
                }
            }
        }
        return false;
    }
    for (let i=0;i<n-2;i++) {
        if (nok(i,'a','z')) return false;
        if (nok(i,'A','Z')) return false;
        if (nok(i,'0','9')) return false;
    }
    return true;
}
