typedef vector<vector<char>> board;
typedef unordered_map<char,bool> mp;

bool valid(board a) {
    mp mrow[9], mcol[9], msqr[9];
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            int k = (i/3) * 3 + (j/3);
            char v = a[i][j];
            if (v != '.' && (mrow[i][v] || mcol[j][v] || msqr[k][v])) return false;
            mrow[i][v] = mcol[j][v] = msqr[k][v] = 1;
        }
    }
    return true;
}

bool sudokuChecking(std::vector<std::vector<char>> grid) {
    return valid(grid);
}
