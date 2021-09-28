class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int x = 0, y = 0;
        vector<int> ans;
        for (int i = 0; i < m * n; i++) {
            ans.push_back(mat[x][y]);
            if ((x + y) % 2 == 0) {
                if (y == n - 1) x++;
                else if (x == 0) y++;
                else {x--; y++;}
            } else {
                if (x == m - 1) y++;
                else if (y == 0) x++;
                else {x++; y--;}
            }
        }
        return ans;
    }
};