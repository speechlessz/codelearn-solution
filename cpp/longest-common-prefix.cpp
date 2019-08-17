class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.size() == 0) return res;
        for (int i = 0; ; i++) {
            if (i >= strs[0].size()) return res;
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) return res;
            }
            res = res + c;
        }
        return res;
    }
};