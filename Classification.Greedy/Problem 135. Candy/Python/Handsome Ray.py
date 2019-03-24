#320ms 2pass
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n=len(ratings)
        if n<=1:
            return n
        candies=[1 for i in xrange(n)]
        for i in xrange(1,n):
            if ratings[i]>ratings[i-1]:
                candies[i]=candies[i-1]+1
        for i in range(n-1,0,-1):
            if ratings[i]<ratings[i-1]:
                candies[i-1]=max(candies[i-1],candies[i]+1)
        result=0
        for i in candies:
            result+=i
        return result