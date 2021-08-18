class Solution {
public:
    vector<vector<int>> dires{{1,0},{0,1},{-1,0},{0,-1}};
    int m, n;
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        int ret = 1;
        for (auto dire: dires) {
            int x2 = x + dire[0];
            int y2 = y + dire[1];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) continue;
            ret += dfs(grid, x2, y2);
        }
        return ret;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};