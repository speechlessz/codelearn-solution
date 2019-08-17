class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;

        vector<string> a;
        for (int i=0;i<=n;i++) dp.push_back(a);
        
        dp[0].push_back("");
        for (int i=1;i<=n;i++) {
            for (int j=0;j<i;j++) {
                vector<string> inStrs = dp[j];
                vector<string> outStrs = dp[i-j-1];
                for (string inStr: inStrs) {
                    for (string outStr: outStrs) {
                        string newStr = "(" + inStr + ")" + outStr;
                        dp[i].push_back(newStr);
                    }
                }
            }    
        }
        
        return dp[n];
    }
};