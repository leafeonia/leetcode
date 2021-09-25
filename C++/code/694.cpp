class Solution {
public:
    
    void dfs(int x, int y) {
        vector<vector<int>> dires{{1,0},{-1,0},{0,1},{0,-1}};
        m_grid[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            auto dire = dires[i];
            int x2 = x + dire[0];
            int y2 = y + dire[1];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || m_grid[x2][y2] == 0) continue;
            curPath += to_string(i) + ",";
            dfs(x2, y2);
        }
        curPath += ".";
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        m_grid = grid;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (m_grid[i][j]) {
                    curPath.clear();
                    dfs(i, j);
                    paths.insert(curPath);
                }
            }
        }
        return paths.size();
    }
    
    string curPath;
    set<string> paths;
    vector<vector<int>> m_grid;
    int m;
    int n;
};