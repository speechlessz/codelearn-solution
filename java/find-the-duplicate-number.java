class Solution {
    public int findDuplicate(int[] nums) {
        HashSet<Integer> m = new HashSet();
        for (int x : nums) {
            if (m.contains(x)) return x;
            m.add(x);
        }
        return -1;
    }
}