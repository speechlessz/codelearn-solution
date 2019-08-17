class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> hash = new HashMap();
        for (int i=0;i<nums.length;i++) {
            int v = nums[i];
            if (hash.containsKey(target-v)) {
                return new int[]{hash.get(target-v), i};
            }
            hash.put(v, i);
        }
        return null;
    }
}
