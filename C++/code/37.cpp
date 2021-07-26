class Solution {
public:
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<int>> grid;
    
    
    int no(int i, int j) {
        return i / 3 * 3 + j / 3;
    }
    
    bool backtrack(vector<vector<char>>& board, int r, int c) {
        if (r == 9) {
            return true;
        }
        if (board[r][c] != '.') {
            if (c == 8) return backtrack(board, r + 1, 0);
            else return backtrack(board, r, c + 1);
        }
        for (int k = 1;k <= 9;k++) {
            if (row[r][k] || col[c][k] || grid[no(r, c)][k]) continue;
            board[r][c] = k + '0';
            row[r][k]++;
            col[c][k]++;
            grid[no(r, c)][k]++;
            if (c == 8) {
                 if (backtrack(board, r + 1, 0)) return true;
            } else {
                if (backtrack(board, r, c + 1)) return true;
            }
            board[r][c] = '.';
            row[r][k]--;
            col[c][k]--;
            grid[no(r, c)][k]--;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        row.resize(9);
        col.resize(9);
        grid.resize(9);
        for (int i = 0;i < 9;i++) {
            row[i].resize(10);
            col[i].resize(10);
            grid[i].resize(10);
        }
        for (int i = 0; i < 9;i++) {
            for (int j = 0;j < 9;j++) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    row[i][val]++;
                    col[j][val]++;
                    grid[no(i, j)][val]++;
                }
            }
        }
        backtrack(board, 0, 0);
    }
};