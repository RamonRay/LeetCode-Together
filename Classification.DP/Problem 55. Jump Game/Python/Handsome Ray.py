class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums)<2:
            return True
        minReachIndex=len(nums)-1
        for i in xrange(len(nums)-1,-1,-1):
            if i+nums[i]>=minReachIndex:
                minReachIndex=i
        return minReachIndex==0
