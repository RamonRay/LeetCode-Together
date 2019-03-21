#not recursively 20ms
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1:
            return 1
        if n == 2:
            return 2

        record = [1, 2] + [0] * (n - 2)
        record[0] = 1
        record[1] = 2
        for i in range(2, n):
            record[i] = record[i - 1] + record[i - 2]
        return record[-1]