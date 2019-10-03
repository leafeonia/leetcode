class Solution:
    def setZeroes(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        if n == 0:
            return
        m = len(matrix[0])
        row0 = False
        column0 = False
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
                    if i == 0:
                        row0 = True
                    if j == 0:
                        column0 = True
        for i in range(1, n):
            if matrix[i][0] == 0:
                for j in range(m):
                    matrix[i][j] = 0

        for i in range(1, m):
            if matrix[0][i] == 0:
                for j in range(n):
                    matrix[j][i] = 0

        if column0:
            for i in range(n):
                matrix[i][0] = 0
        if row0:
            for i in range(m):
                matrix[0][i] = 0