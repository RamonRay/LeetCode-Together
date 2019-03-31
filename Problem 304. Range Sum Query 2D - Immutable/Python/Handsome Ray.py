class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        self.matrix = matrix
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return
        for row in range(len(self.matrix)):
            for column in range(1, len(self.matrix[0])):
                self.matrix[row][column] += self.matrix[row][column - 1]
        for row in range(1, len(self.matrix)):
            for column in range(len(self.matrix[0])):
                self.matrix[row][column] += self.matrix[row - 1][column]
        rows = len(matrix)
        columns = len(matrix[0])
        self.matrix = [[0 for i in range(columns)]] + self.matrix
        for i in range(rows + 1):
            self.matrix[i].insert(0, 0)
            # print self.matrix[i]

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        return self.matrix[row2 + 1][col2 + 1] + self.matrix[row1][col1] - self.matrix[row1][col2 + 1] - \
               self.matrix[row2 + 1][col1]

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)