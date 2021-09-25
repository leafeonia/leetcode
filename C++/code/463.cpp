class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dires{{1,0},{0,1},{-1,0},{0,-1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                for (auto dire: dires) {
                    int x = i + dire[0];
                    int y = j + dire[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || !grid[x][y]) ans++;
                }
            }
        }
        return ans;
    }
};