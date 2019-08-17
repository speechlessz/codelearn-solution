class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for (int i=0;i<nums.size();i++) {
            int v = nums[i];
            if (hash.find(target-v) != hash.end()) {
                return vector<int>{hash[target-v], i};
            }
            hash[v] = i;
        }
        return vector<int>{};
    }
};
