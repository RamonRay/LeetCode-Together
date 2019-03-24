#Adding and Sorting in revered order to avoid insertion and moving 20ms
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        index1 = m + n - 1
        index2 = n - 1
        while index1 >= 0:
            if index2 < 0:
                break
            if index2 == index1:
                nums1[index1] = nums2[index2]
                index2 -= 1
                index1 -= 1
                continue
            if nums1[index1 - index2 - 1] > nums2[index2]:
                nums1[index1] = nums1[index1 - index2 - 1]
                index1 -= 1
            else:
                nums1[index1] = nums2[index2]
                index1 -= 1
                index2 -= 1
