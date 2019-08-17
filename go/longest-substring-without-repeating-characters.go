func lengthOfLongestSubstring(s string) int {
	var a [256]bool
	var res, l, r int
	for ; r < len(s); r++ {
		if a[int(s[r])] {
			for s[l] != s[r] {
				a[int(s[l])] = false
				l++
			}
			l++
		}
		a[int(s[r])] = true
		if r-l+1 > res {
			res = r - l + 1
		}
	}
	return res
}