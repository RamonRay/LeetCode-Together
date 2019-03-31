#using dp and binary search for best result
class Solution(object):
    def superEggDrop(self, K, N):
        """
        :type K: int
        :type N: int
        :rtype: int
        """
        record = {}

        def dp(k, n):
            if (k, n) in record:
                return record[k, n]
            if n == 0:
                return 0
            if k == 1:
                return n
            low, high = 1, n
            while low + 1 < high:
                x = (low + high) / 2
                dp1 = dp(k - 1, x - 1)
                dp2 = dp(k, n - x)

                if dp1 < dp2:
                    low = x
                elif dp1 > dp2:
                    high = x
                else:
                    low = high = x
            ans = 1 + min(max(dp(k - 1, x - 1), dp(k, n - x)) for x in range(low, high + 1))
            record[k, n] = ans
            return ans
        return dp(K, N)
