class Solution {
    public int maxAbsValExpr(int[] arr1, int[] arr2) {
        int [][]dire = {{1,1,1},{1,1,-1},{1,-1,1},{1,-1,-1}};//,{-1,1,1},{-1,-1,1},{-1,1,-1},{-1,-1,-1}};
        int ans = 0;
        for (int i = 0;i < 4;i++){
            int mini = Integer.MAX_VALUE;
            int maxi = Integer.MIN_VALUE;
            int dx = dire[i][0];
            int dy = dire[i][1];
            int dz = dire[i][2];
            for(int j = 0;j < arr1.length;j++){
                mini = Math.min(mini, arr1[j]*dx + arr2[j]*dy + j*dz);
                maxi = Math.max(maxi, arr1[j]*dx + arr2[j]*dy + j*dz);
            }
            ans = Math.max(ans,maxi-mini);
        }
        return ans;
    }
}