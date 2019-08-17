func searchRange(nums []int, target int) []int {
	l, r := 0, len(nums)-1
	first, last := -1, -1

	for l <= r {
		m := (l + r) / 2
		if nums[m] >= target {
			first, r = m, m-1
		} else {
			l = m + 1
		}
	}

	if first == -1 || nums[first] != target {
		return []int{-1, -1}
	}

	l, r = 0, len(nums)-1
	for l <= r {
		m := (l + r) / 2
		if nums[m] <= target {
			last, l = m, m+1
		} else {
			r = m - 1
		}
	}

	return []int{first, last}
}