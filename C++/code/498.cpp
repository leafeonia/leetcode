class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        for (int i = 0; i < m + n - 1; i++) {
            vector<int> temp;
            if (i % 2 == 0) {
                for (int x = i; x >= 0; x--) {
                    int y = i - x;
                    if (x >= m || y >= n) continue;
                    ans.push_back(mat[x][y]);
                }
            } else {
                for (int x = 0; x <= i; x++) {
                    int y = i - x;
                    if (x >= m || y >= n) continue;
                    ans.push_back(mat[x][y]);
                }
            }
        }
        return ans;
    }
};