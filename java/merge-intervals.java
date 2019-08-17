/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res =  new ArrayList();
        if (intervals.isEmpty()) return res;
        
        intervals.sort((Interval a, Interval b) -> 
                       (a.start < b.start || (a.start == b.start && a.end > b.end)) ? -1 : 1);
        
        Interval cur = intervals.get(0);
        for (Interval p : intervals) {
            if (p.start > cur.end) {
                res.add(cur);
                cur = p;
            } else {
                cur.end = Math.max(cur.end, p.end);
            }
        }
        res.add(cur);
        return res;
    }
}