/**
 * Definition for an interval.
 * type Interval struct {
 *	   Start int
 *	   End   int
 * }
 */
func merge(intervals []Interval) []Interval {
	if len(intervals) == 0 {
		return []Interval{}
	}

	sort.SliceStable(intervals, func(i, j int) bool {
		a, b := intervals[i], intervals[j]
		return a.Start < b.Start || (a.Start == b.Start && a.End > b.End)
	})

	res := []Interval{}
	cur := intervals[0]
	for _, p := range intervals {
		if p.Start > cur.End {
			res = append(res, cur)
			cur = p
		} else {
			if p.End > cur.End {
				cur.End = p.End
			}
		}
	}
	res = append(res, cur)
	return res
}
