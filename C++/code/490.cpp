class Solution {
public:
    int dx, dy, m, n;
    vector<vector<int>> maze;
    vector<vector<int>> visited;
    vector<vector<int>> dires{{0,1},{0,-1},{-1,0},{1,0}};
    
    bool dfs(int x, int y) {
        if (visited[x][y]) return false;
        if (x == dx && y == dy) return true;
        visited[x][y] = 1;
        for (auto& dire: dires) {
            int x2 = x, y2 = y;
            while (valid(x2 + dire[0], y2 + dire[1])) {
                x2 += dire[0];
                y2 += dire[1];
            }
            if (dfs(x2, y2)) return true;
        }
        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this->maze = maze;
        m = maze.size();
        n = maze[0].size();
        visited.resize(m, vector<int>(n, 0));
        dx = destination[0];
        dy = destination[1];
        return dfs(start[0], start[1]);
    }
    
    bool valid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n && !maze[x][y];
    }
};