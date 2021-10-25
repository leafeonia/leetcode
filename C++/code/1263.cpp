class Solution {
public:
    vector<vector<int>> dires{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int m, n;
    vector<vector<char>> grid;
    
    bool reachable(int sx, int sy, int dx, int dy, int bx, int by) {
        queue<pair<int,int>> q;
        q.push({sx, sy});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sx][sy] = 1;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int x = front.first, y = front.second;
            if (x == dx && y == dy) return true;
            for (auto& dire: dires) {
                int x2 = x + dire[0], y2 = y + dire[1];
                if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || (x2 == bx && y2 == by) || grid[x2][y2] == '#' || visited[x2][y2]) continue;
                q.push({x2, y2});
                visited[x2][y2] = 1;
            }
        }
        return false;
    }
    
    
    int minPushBox(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        vector<vector<int>> visited(m * n, vector<int>(m * n, 0));
        
        int endx, endy, boxx, boxy, px, py;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'T') {
                    endx = i;
                    endy = j;
                } else if (grid[i][j] == 'B') {
                    boxx = i;
                    boxy = j;
                } else if (grid[i][j] == 'S') {
                    px = i;
                    py = j;
                }
            }
        }
        
        int ans = 0;
        queue<pair<int,int>> q;
        q.push({boxx * n + boxy, px * n + py});
        while (!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto front = q.front();
                q.pop();
                int bx = front.first / n, by = front.first % n;
                if (bx == endx && by == endy) return ans;
                int px = front.second / n, py = front.second % n;
                for (auto& dire: dires) {
                    int bx2 = bx + dire[0], by2 = by + dire[1];
                    int px2 = bx - dire[0], py2 = by - dire[1];
                    if (bx2 < 0 || bx2 >= m || by2 < 0 || by2 >= n || px2 < 0 || px2 >= m || py2 < 0 || py2 >= n ||
                       grid[bx2][by2] == '#' || grid[px2][py2] == '#' || visited[bx * n + by][px2 * n + py2]) continue;
                    if (!reachable(px, py, px2, py2, bx, by)) continue;
                    visited[bx * n + by][px2 * n + py2] = 1;
                    q.push({bx2 * n + by2, bx * n + by});
                }
            }
            ans++;
        }
        return -1;
    }
    
    
};