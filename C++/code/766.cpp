class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < n; i++) {
            int val = matrix[0][i];
            int x = 0, y = i;
            while (x < m && y < n) {
                if (matrix[x++][y++] != val) return false;
            }
        }
        for (int i = 1; i < m; i++) {
            int val = matrix[i][0];
            int x = i, y = 0;
            while (x < m && y < n) {
                if (matrix[x++][y++] != val) return false;
            }
        }
        return true;
    }
};