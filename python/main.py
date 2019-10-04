from Solution import *

solution = Solution()
board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
ret = solution.exist(board, "ABFS")
print(ret)