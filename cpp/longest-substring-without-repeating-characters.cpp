class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool *a = new bool[256];
        for (int i=0;i<256;i++) a[i] = false;
        int res = 0, l = 0, r = 0;
        while (r < s.size()) {
            if (a[int(s[r])]) {
                while (s[l] != s[r]) a[int(s[l])] = false, l++;
                l++;
            }
            a[int(s[r])] = true;
            res = max(res, r-l+1);
            r++;
        }
        return res;
    }
};