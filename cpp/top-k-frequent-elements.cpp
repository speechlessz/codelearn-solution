class Solution {
public:
    struct Data {
        int num, cnt;
        bool operator < (const Data &o) const {
            return cnt < o.cnt;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int x: nums) m[x]++;
        
        priority_queue<Data> st;
        for (auto x: m) {
            st.push({ x.first, x.second });
        }
        
        vector<int> res;
        while (k--) {
            Data u = st.top();
            res.push_back(u.num);
            st.pop();
        }
        
        return res;
    }
};