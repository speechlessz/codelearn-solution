/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let l = 0, r = nums.length-1, first = -1, last = -1;
    
    while (l <= r) {
        const m = Math.floor((l+r)/2);
        if (nums[m] >= target) {
            first = m;
            r = m-1;
        } else {
            l = m+1;
        }
    }
    if (first == -1 || nums[first] != target) return [-1, -1];
    
    l = 0; r = nums.length-1;
    while (l <= r) {
        const m = Math.floor((l+r)/2);
        if (nums[m] <= target) {
            last = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }
    
    return [first, last];
};