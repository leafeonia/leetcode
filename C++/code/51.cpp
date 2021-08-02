class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<char>> board;
    set<int> row, col, diag, diag2;
    
    void backtrack(int cur, int n, int row) {
        if (cur == n) {
            vector<string> sol;
            for (int i = 0; i < n;i++) {
                string s;
                for (int j = 0;j < n;j++) {
                    s += board[i][j];
                }
                sol.push_back(s);
            }
            ans.push_back(sol);
            return;
        }
        for (int j = 0;j < n;j++) {
            if (col.find(j) == col.end() && diag.find(row + j) == diag.end() && diag2.find(row - j) == diag2.end()) {
                    col.insert(j);
                    diag.insert(row + j);
                    diag2.insert(row - j);
                    board[row][j] = 'Q';
                    backtrack(cur + 1, n, row + 1);
                    board[row][j] = '.';
                    col.erase(j);
                    diag.erase(row + j);
                    diag2.erase(row - j);
                    board[row][j] = '.';
            }    
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n);
        for(int i = 0;i < n;i++) board[i].resize(n, '.');
        backtrack(0, n, 0);
        return ans;
    }
};