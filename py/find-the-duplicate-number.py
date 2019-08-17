class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        m = set()
        for x in nums:
            if x in m: return x
            m.add(x)
