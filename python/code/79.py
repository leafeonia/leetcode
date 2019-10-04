class Solution:
    def dfs(self,i, j, board, word):
        if len(word) == 0:
            return True
        if i < 0 or j < 0 or i >= self.n or j >= self.m or board[i][j] != word[0] or self.visited[i][j]:
            return False
        if board[i][j] == word[0]:
            self.visited[i][j] = True
            word_ = word[1:]
            if self.dfs(i+1, j, board, word_) or self.dfs(i, j+1, board, word_) or self.dfs(i-1, j, board, word_) or self.dfs(i, j-1, board, word_):
                return True
            self.visited[i][j] = False
        return False

    def exist(self, board, word):
        self.n = len(board)
        if self.n == 0:
            return False
        self.m = len(board[0])
        self.visited = [[False for i in range(self.m)] for j in range(self.n)]
        for i in range(self.n):
            for j in range(self.m):
                if board[i][j] == word[0]:
                    if self.dfs(i, j, board, word):
                        return True
        return False