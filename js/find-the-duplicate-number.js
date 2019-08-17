/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    const m = {};
    for (let x of nums) {
        if (m[x]) return x;
        m[x] = 1;
    }
};