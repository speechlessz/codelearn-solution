class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        dp = [[] for i in range(n+1)]
        dp[0].append("")
        
        for i in range(1,n+1):
            for j in range(i):
                inStrs = dp[j]
                outStrs = dp[i-j-1]
                for inStr in inStrs:
                    for outStr in outStrs:
                        newStr = "(" + inStr + ")" + outStr
                        dp[i].append(newStr)
        
        return dp[n]