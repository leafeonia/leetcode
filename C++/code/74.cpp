class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size();
        int col = matrix[0].size() - 1;
        while(col >= 0){
            for(int i = 0;i < row;i++){
                if(matrix[i][col] == target) return true;
                if(matrix[i][col] > target) break;
            }
            col--;
        }
        return false;
    }
};