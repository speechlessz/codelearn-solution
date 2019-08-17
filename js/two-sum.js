/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    hash = {}
    for (let i in nums) {
        v = nums[i]
        if (hash[target - v] != null) {
            return [hash[target - v], i]
        }
        hash[v] = i
    }
    return null
};
