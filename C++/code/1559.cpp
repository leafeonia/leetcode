class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<int>> dires{{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<char>> m_grid;
    int m, n;
    
    bool dfs(int x, int y, int px, int py) {
        if (visited[x][y]) {
            return true;
        }     
        visited[x][y] = 1;
        bool ret = false;
        for (auto dire: dires) {
            int x2 = x + dire[0], y2 = y + dire[1];
            if ((x2 == px && y2 == py) || x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || m_grid[x2][y2] != m_grid[x][y]) continue;
            ret |= dfs(x2, y2, x, y);
        }
        return ret;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        m_grid = grid;
        visited.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(i, j, -1, -1)) {
                        cout << i << " " << j << endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};