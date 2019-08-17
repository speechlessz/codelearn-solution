/**
 * Definition for an interval.
 * function Interval(start, end) {
 *     this.start = start;
 *     this.end = end;
 * }
 */
/**
 * @param {Interval[]} intervals
 * @return {Interval[]}
 */
var merge = function(intervals) {
    if (intervals.length == 0) return [];
    
    intervals.sort((a, b) => (a.start < b.start || (a.start == b.start && a.end > b.end)) ? -1 : 1)

    let res = [];
    let cur = intervals[0];
    for (let p of intervals) {
        if (p.start > cur.end) {
            res.push(cur);
            cur = p;
        } else {
            cur.end = Math.max(cur.end, p.end)
        }
    }
    res.push(cur);
    return res;
};