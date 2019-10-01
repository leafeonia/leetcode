import java.util.ArrayList;
import java.util.List;

class Solution {
    int dires[][] = {{0,1},{1,0},{0,-1},{-1,0}};
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix.length == 0) return new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        int n = matrix.length;
        int m = matrix[0].length;
        boolean used[][] = new boolean[n][m];
        int dire = 0;
        int x = 0,y = 0;
        int cnt = n*m;
        while(cnt > 0){
            cnt--;
            ans.add(matrix[x][y]);
            used[x][y] = true;
            int x_next = x + dires[dire][0];
            int y_next = y + dires[dire][1];
            if (x_next < 0 || y_next < 0 || x_next >= n || y_next >= m || used[x_next][y_next]) dire = (dire + 1) % 4;
            x += dires[dire][0];
            y += dires[dire][1];
        }
        return ans;
    }
}