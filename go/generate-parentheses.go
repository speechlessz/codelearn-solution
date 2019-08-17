func generateParenthesis(n int) []string {
	dp := make([][]string, n+1)
	dp[0] = append(dp[0], "")
	dp[1] = append(dp[1], "()")
	// should initialize from n = 1, because "" in Golang
	for i := 2; i <= n; i++ {
		for j := 0; j < i; j++ {
			inStrs := dp[j]
			outStrs := dp[i-j-1]
			for _, inStr := range inStrs {
				for _, outStr := range outStrs {
					newStr := "(" + inStr + ")" + outStr
					dp[i] = append(dp[i], newStr)
				}
			}
		}
	}

	return dp[n]
}