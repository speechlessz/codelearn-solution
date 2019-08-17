class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = -1, last = -1;
        int l = 0, r = nums.length-1;
        
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] >= target) {
                first = m; r = m-1;
            } else {
                l = m+1;
            }
        }
        
        if (first == -1 || nums[first] != target) return new int[]{ -1, -1 };
        
        l = 0; r = nums.length-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (nums[m] <= target) {
                last = m; l = m+1;
            } else {
                r = m-1;
            }
        }
        
        return new int[] { first, last };
    }
}