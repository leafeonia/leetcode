import java.util.Vector;

class Solution {
    public int ch2int(char ch){
        if(ch == '.') return 0;
        return ch - '0';
    }
    public boolean valid(Vector<Integer> v){
        int counter[] = {0,0,0,0,0,0,0,0,0,0};
        for (Integer i: v) {
            counter[i]++;
            if(counter[i] > 1 && i > 0) return false;
        }
        return true;
    }
    public boolean isValidSudoku(char[][] board) {
        Vector<Integer> v = new Vector<>();
        for(int i = 0;i < 9;i++){
            v.clear();
            for(int j = 0;j < 9;j++){
                v.addElement(ch2int(board[i][j]));
            }
            if(!valid(v)) return false;
            v.clear();
            for(int j = 0;j < 9;j++){
                v.addElement(ch2int(board[j][i]));
            }
            if(!valid(v)) return false;
        }
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                int x = 3*i;
                int y = 3*j;
                v.clear();
                for (int k = 0;k < 3;k++){
                    for(int l = 0;l < 3;l++){
                        v.addElement(ch2int(board[x+k][y+l]));
                    }
                }
                if (!valid(v)) return false;
            }
        }
        return true;
    }
}