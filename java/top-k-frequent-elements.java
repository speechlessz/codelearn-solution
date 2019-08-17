class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> m = new HashMap();
        
        for (int x: nums) {
            m.put(x, m.getOrDefault(x, 0) + 1);
        }
        
        PriorityQueue<Integer> st = new PriorityQueue<Integer>((x, y) -> m.get(y)-m.get(x));
        
        for (int x: m.keySet()) st.add(x);
        
        List<Integer> res = new ArrayList();
        
        while (k-- > 0) res.add(st.poll());
        
        return res;
    }
}