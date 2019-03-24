#DP
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows=len(grid)
        cols=len(grid[0])
        dp=[[0 for i in xrange(cols)] for j in xrange(rows)]
        for row in range(rows):
            for col in range(cols):
                if row==0 and col==0:
                    dp[row][col]=grid[row][col]
                    continue
                if row==0:
                    dp[row][col]=dp[row][col-1]+grid[row][col]
                    continue
                if col==0:
                    dp[row][col]=dp[row-1][col]+grid[row][col]
                    continue
                dp[row][col]=min(dp[row-1][col],dp[row][col-1])+grid[row][col]
        return dp[rows-1][cols-1]