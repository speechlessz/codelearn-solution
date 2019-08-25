int modePrefix(std::string s) {
    int res = 0;
    for (char c: s) res += c == s[0];
    return res;
}

