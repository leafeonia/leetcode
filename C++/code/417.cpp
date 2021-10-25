class Solution {
public:
    int m, n;
    vector<vector<int>> pac;
    vector<vector<int>> atl;
    vector<vector<int>> heights;
    vector<vector<int>> dires{{-1,0},{1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (grid[x][y]) return;
        grid[x][y] = 1;
        for (auto& dire: dires) {
            int x2 = x + dire[0], y2 = y + dire[1];
            if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && heights[x2][y2] >= heights[x][y]) {
                dfs(grid, x2, y2);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        m = heights.size();
        n = heights[0].size();
        pac.resize(m, vector<int>(n, 0));
        atl.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(pac, i, 0);
            dfs(atl, i, n - 1);
        }
        for (int i = 0; i < n; i++) {
            dfs(pac, 0, i);
            dfs(atl, m - 1, i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    vector<int> v{i, j};
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};