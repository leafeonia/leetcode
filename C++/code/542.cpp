class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dire{{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ans(m, vector<int>(n, -1));
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }    
        }
        int dist = 0;
        while (!q.empty()) {
            dist++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                for (int j = 0; j < 4; j++){
                    int x2 = x + dire[j][0];
                    int y2 = y + dire[j][1];
                    if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || ans[x2][y2] != -1) continue;
                    ans[x2][y2] = dist;
                    q.push({x2, y2});
                }
            }
        }
        return ans;
    }
};