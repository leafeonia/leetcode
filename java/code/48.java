class Solution {
    public void rotate_layer(int[][] matrix, int layer){
        int n = matrix.length;

    }
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0;i < n / 2;i++){
            rotate_layer(matrix, i);
        }
    }
}