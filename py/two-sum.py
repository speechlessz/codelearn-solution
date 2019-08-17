class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hash = dict()
        for i in range(len(nums)):
            v = nums[i]
            if hash.get(target-v) != None: return [hash.get(target-v), i]
            hash[v] = i
        return None
