
class Solution {
    public void rotate_layer(int[][] matrix, int layer){
        int n = matrix.length;
        for (int i = layer;i < n - layer - 1;i++){
            int temp = matrix[layer][i];
            matrix[layer][i] = matrix[n - 1 - i][layer];
            matrix[n-1-i][layer] = matrix[n-1-layer][n-1-i];
            matrix[n-1-layer][n-1-i] = matrix[i][n-1-layer];
            matrix[i][n-1-layer] = temp;
        }
    }
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0;i < n / 2;i++){
            rotate_layer(matrix, i);
        }
    }
}