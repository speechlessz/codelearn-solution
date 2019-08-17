func topKFrequent(nums []int, k int) []int {
	m := map[int]int{}
	for _, v := range nums {
		m[v]++
	}

	type data struct {
		num, cnt int
	}

	st := []data{}
	for i, v := range m {
		st = append(st, data{i, v})
	}

	sort.SliceStable(st, func(i, j int) bool {
		return st[i].cnt > st[j].cnt
	})

	res := make([]int, k)
	for i := 0; i < k; i++ {
		res[i] = st[i].num
	}

	return res
}
