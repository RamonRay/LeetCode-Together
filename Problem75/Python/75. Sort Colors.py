
def sortColors(nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        quickSort(nums,0,len(nums)-1)
        return nums
def quickSort(nums,left,right):
    if left>=right:
        return
    key=nums[left]
    low=left
    high=right
    while low<high:
        while low<high and nums[high]>=key:
            high-=1
        nums[low]=nums[high]
        while low<high and nums[low]<=key:
            low+=1
        nums[high]=nums[low]
    nums[low]=key
    quickSort(nums,left,low-1)
    quickSort(nums,low+1,right)
def newQuickSort(nums):
    if len(nums)<=1:
        return nums
    return newQuickSort([i for i in nums[1:] if nums[i] <= nums[0]]) + [nums[0]] + newQuickSort([i for i in nums[1:] if nums[i] > nums[0]])
nums=[2,0,2,1,1,0]

print newQuickSort(nums)