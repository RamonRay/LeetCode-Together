#radixSort O(digits*(index+n)) 56ms
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0
        nums = self.radixSort(nums)
        prev = nums[0]
        gap = -1
        for i in nums[1:]:
            if gap < i - prev:
                gap = i - prev
            prev = i
        return gap

    def radixSort(self, nums):
        for k in xrange(10):
            tmp = [[] for i in xrange(10)]
            for i in nums:
                tmp[i / 10 ** k % 10].append(i)
            nums = [a for b in tmp for a in b]
        return nums
#bucketSort O(n) 44ms
class Bucket(object):
    def __init__(self):
        self.isUsed=False
        self.maxVal=-float("inf")
        self.minVal=float("inf")
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n=len(nums)
        if n<2:
            return 0
        maxNum=max(nums)
        minNum=min(nums)
        bucketSize=max(1,(maxNum-minNum)//(n-1))
        bucketNum=(maxNum-minNum)//(bucketSize)+1
        buckets=[Bucket() for i in range(bucketNum)]
        for i in nums:
            index=(i-minNum)//bucketSize
            buckets[index].isUsed=True
            buckets[index].maxVal=max(buckets[index].maxVal,i)
            buckets[index].minVal=min(buckets[index].minVal,i)
        prev=None
        gap=0
        for i in buckets:
            if i.isUsed==False:
                continue
            if prev!=None:
                tmp=i.minVal-prev
                if tmp>gap:
                    gap=tmp
            prev=i.maxVal
        return gap
#quickSort 20ms...
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return 0
        nums.sort()
        gap=0
        prev=nums[0]
        for i in nums[1:]:
            tmp=i-prev
            if tmp>gap:
                gap=tmp
            prev=i
        return gap            