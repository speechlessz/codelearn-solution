func twoSum(nums []int, target int) []int {
    hash := make(map[int]int)
    for i,v := range(nums) {
        if _, ok := hash[target-v]; ok {
            return []int { hash[target-v], i }
        }
        hash[v] = i
    }
    return nil
}
