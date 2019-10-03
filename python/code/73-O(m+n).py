class Solution:
    def setZeroes(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n == 0:
            return
        m = len(matrix[0])
        row = [False] * n
        column = [False] * m
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[i] = True
                    column[j] = True
        for i in range(n):
            if row[i]:
                for j in range(m):
                    matrix[i][j] = 0
        for i in range(m):
            if column[i]:
                for j in range(n):
                    matrix[j][i] = 0

