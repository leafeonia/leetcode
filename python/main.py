# from Solution import *
#
# solution = Solution()
# board = [
#   ['A','B','C','E'],
#   ['S','F','C','S'],
#   ['A','D','E','E']
# ]
# ret = solution.exist(board, "ABFS")
# print(ret)

import numpy as np
d = np.zeros(10)
a, b = 1, 1
d[1] = d[2] = 1
for i in range(2, 1000):
    a, b = b, a+b
    i = int(str(b)[0])
    d[i] += 1
for i in range(1,10):
    print("The number beginning with %d appears %d times，the ratio is %.3f" % (i, d[i], d[i] / 1000))
    print()