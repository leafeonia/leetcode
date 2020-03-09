class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int col = m - 1;
        int row = 0;
        while(col >= 0){
            while(matrix[row][col] <= target){
                if(matrix[row][col] == target) return true;
                row++;
                if(row == n) return false;
            }
            
            col--;
        }
        return false;
    }
};