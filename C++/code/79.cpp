class Solution {
public:
    void dfs(int x, int y, string word) {
        if (found || x < 0 || x >= m || y < 0 || y >= n || m_board[x][y] != word[0]) return;
        m_board[x][y] = '#';
        if (word.length() == 1) {
            found = true;
            return;
        }
        for (auto& dire: dires) {
            dfs(x + dire[0], y + dire[1], word.substr(1));
        }
        m_board[x][y] = word[0];
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m_board = board;
        m = board.size();
        n = board[0].size();
        found = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, word);
            }
        }
        return found;
    }
    
    vector<vector<int>> dires{{1,0},{-1,0},{0,1},{0,-1}};
    bool found;
    vector<vector<char>> m_board;
    int m, n;
};