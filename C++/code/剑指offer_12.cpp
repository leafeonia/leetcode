class Solution {
public:
    vector<vector<int>> visited;
    string word;
    int x_max;
    int y_max;
    bool dfs(int x, int y, int index, vector<vector<char>>& board){
        if (index == word.length()) return true;
        if (x < 0 || x >= x_max || y < 0 || y >= y_max) return false;
        if (visited[x][y] == 1) return false;
        if (board[x][y] != word[index]) return false;
        visited[x][y] = 1;
        bool valid = dfs(x+1, y, index+1, board) || dfs(x-1, y, index+1, board) || dfs(x, y+1, index+1, board) || dfs(x, y-1, index+1, board);
        visited[x][y] = 0;
        return valid;

    }

    bool exist(vector<vector<char>>& board, string word2) {
        if (board.empty()) return false;
        word = word2;
        x_max = board.size();
        y_max = board[0].size();
        visited = vector<vector<int>>(x_max, vector<int>(y_max, 0));
        for(int i = 0;i < x_max;i++){
            for(int j = 0;j < y_max;j++){
                if (dfs(i, j, 0, board)) return true;
            }
        }
        return false;
    }



};


