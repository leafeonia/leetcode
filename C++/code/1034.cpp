class Solution {
public:
    vector<vector<int>> dires = {{-1,0},{1,0},{0,1},{0,-1}};
    vector<vector<int>> visited;
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int x, int y, int color) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] != color) return;
        visited[x][y] = 1;
        int adj = 0;
        for (auto& dire: dires) {
            int x2 = x + dire[0], y2 = y + dire[1];
            if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && abs(grid[x2][y2]) == color) adj++;
        }
        if (adj < 4) grid[x][y] = -grid[x][y];
        for (auto& dire: dires) {
            dfs(grid, x + dire[0], y + dire[1], color);
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> ans = grid;
        m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<int>(n, 0));
        dfs(ans, row, col, grid[row][col]);
        for (auto& row: ans) {
            for (int i = 0; i < row.size(); i++) {
                if (row[i] < 0) row[i] = color;
            }
        }
        return ans;
    }
};