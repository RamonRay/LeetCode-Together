class Solution(object):
    def numRescueBoats(self, people, limit):
        """
        :type people: List[int]
        :type limit: int
        :rtype: int
        """
        people.sort()
        n=len(people)
        i=0
        j=n-1
        while i<=j:
            if people[i]+people[j]<=limit:
                i+=1
            j-=1
        return n-j-1