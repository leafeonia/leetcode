class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = m + n - 2;i >= 0;i--){
            for(int j = 0;j <= i;j++){
                if(j >= m) continue;
                if(i - j >= n) continue;
                if(j == m - 1 && i - j == n - 1) continue;
                grid[j][i-j] += min((j == m - 1 ? 0x3f3f3f3f : grid[j+1][i-j]), (i - j == n - 1 ? 0x3f3f3f3f : grid[j][i-j+1]));
            }
        }
        return grid[0][0];
    }
};