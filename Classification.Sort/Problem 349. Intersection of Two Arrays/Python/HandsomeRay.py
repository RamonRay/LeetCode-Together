#1Using Hash 20ms
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        map={}
        ans=[]
        for i in nums1:
            map[i]=1
        for i in nums2:
            if i in map and map[i]==1:
                ans.append(i)
                map[i]=0
        return ans

#Brute Force 44ms
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ans=[]
        for i in nums1:
            if i not in ans and i in nums2:
                ans.append(i)
        return ans
#Search After Sorting 24ms
class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1.sort()
        nums2.sort()
        ans=[]
        i=j=0
        k=None
        while i<len(nums1) and j<len(nums2):
            if nums1[i]==k:
                i+=1
            if nums2[j]==k:
                j+=1
                continue
            if nums1[i]==nums2[j]:
                ans.append(nums1[i])
                k=nums1[i]
                i+=1
                j+=1
            elif nums1[i]<nums2[j]:
                i+=1
            else:
                j+=1
        return ans