class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        typedef pair<int,int> pi;
        auto comp = [&](pi a, pi b){return grid[a.first][a.second] < grid[b.first][b.second];};
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        pq.push({0,0});
        int m = grid.size(), n = grid[0].size();
        int record = grid[0][0];
        vector<vector<int>> dires{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int x = top.first, y = top.second;
            if (visited[x][y]) continue;
            visited[x][y] = 1;
            record = min(record, grid[x][y]);
            if (x == m - 1 && y == n - 1) return record;
            for (auto& dire: dires) {
                int x2 = x + dire[0], y2 = y + dire[1];
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) pq.push({x2, y2});
            }
        }
        return record;
    }
};