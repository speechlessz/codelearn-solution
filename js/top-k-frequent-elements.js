/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const m = {}
    nums.forEach(x => m[x] = (m[x] || 0) + 1)
    
    const st = [];
    for (let x in m) {
        st.push({ num: x, cnt: m[x] })
    }
    
    st.sort((a, b) => b.cnt - a.cnt)
    const res = st.slice(0, k).map(x => x.num);
    return res;
};