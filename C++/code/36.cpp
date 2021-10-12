class Solution {
public:
    int id(int x, int y) {
        return x / 3 * 3 + y / 3;    
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        vector<unordered_set<int>> grid(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[i][j])) continue;
                int num = board[i][j] - '0';
                if (row[i].find(num) != row[i].end()) return false;
                else row[i].insert(num);
                if (col[j].find(num) != col[j].end()) return false;
                else col[j].insert(num);
                if (grid[id(i, j)].find(num) != grid[id(i, j)].end()) return false;
                else grid[id(i, j)].insert(num);
            }
        }
        return true;
    }
};