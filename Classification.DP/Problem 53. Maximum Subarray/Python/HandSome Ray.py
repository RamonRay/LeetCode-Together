#DP 20ms
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxAll = nums[0]
        maxHere = nums[0]
        for i in nums[1:]:
            if maxHere > 0:
                maxHere = maxHere + i
            else:
                maxHere = i
            if maxHere > maxAll:
                maxAll = maxHere
        return maxAll
