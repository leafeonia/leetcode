class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int searched = 0;
        vector<vector<int>> total(m, vector(n, 0));
        vector<vector<int>> dires{{0,1},{1,0},{0,-1},{-1,0}};
        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = -1;
                    auto dist = grid;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto pos = q.front();
                        q.pop();
                        int x0 = pos.first, y0 = pos.second;
                        for (auto& dire: dires) {
                            int x = x0 + dire[0];
                            int y = y0 + dire[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != searched) continue;
                            grid[x][y]--;
                            dist[x][y] = dist[x0][y0] + 1;
                            total[x][y] += dist[x][y] - 1;
                            q.push({x, y});
                            if (ans == -1 || ans > total[x][y]) ans = total[x][y];
                        }
                    }
                    
                    searched--;
                }
            }
        }
        return ans;
    }
};