function sequenceFixing(s){
    let t = 0, res = 0;
    for (let c of s) {
        t += c == '(' ? 1 : -1;
        if (t < 0) {
            res++; t = 0;
        }
    }
    return res+t;
}

