function sudokuChecking(a){
    const check = (a) => {
        let m = {};
        for (let i=0;i<9;i++) {
            if (a[i] == '.') continue;
            if (m[a[i]]) return false;
            m[a[i]] = true;
        }
        return true;
    }

    for (let i=0;i<9;i++) {
        if (!check(a[i])) return false;
        let b = [];
        for (let j=0;j<9;j++) b.push(a[j][i]);
        if (!check(b)) return false;
        let c = [];
        let row = Math.floor(i/3);
        let col = i%3;
        for (let j=0;j<3;j++) {
            for (let k=0;k<3;k++) {
                let ii = parseInt(row*3 + j);
                let jj = parseInt(col*3 + k);
                c.push(a[ii][jj]);
            }
        }
        if (!check(c)) return false;
    }
    return true;
}
