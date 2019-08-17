func findDuplicate(nums []int) int {
	m := map[int]bool{}
	for _, x := range nums {
		_, ok := m[x]
		if ok {
			return x
		}
		m[x] = true
	}
	return -1
}