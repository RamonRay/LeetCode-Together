class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n=len(A)
        if n<3:
            return 0
        ans=0
        dp=[0]*n
        last=A[1]-A[0]
        for i in xrange(2,n):
            tmp=A[i]-A[i-1]
            if tmp==last:
                dp[i]=dp[i-1]+1
            last=tmp
        return sum(dp)