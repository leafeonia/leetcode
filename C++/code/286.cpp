class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        int m = rooms.size();
        int n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dist = 1;
        vector<vector<int>> dires{{1,0},{0,1},{-1,0},{0,-1}};
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                for (auto dire: dires) {
                    int x2 = x + dire[0];
                    int y2 = y + dire[1];
                    if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && rooms[x2][y2] == INT_MAX) {
                        rooms[x2][y2] = dist; // update rooms here
                        q.push({x2, y2});
                    }
                }
            }
            dist++;
        }
    }
};