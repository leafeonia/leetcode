#define FAIL 0x3f3f3f3f

class TicTacToe {
public:
    int* lines;
    int n;
    /** Initialize your data structure here. */
    TicTacToe(int N) {
        n = N;
        lines = new int[2*n + 3];
        memset(lines, 0, sizeof(int) * (2*n+3));
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
            if(lines[row] >= 0 && lines[row] != FAIL) {
                lines[row]++;
                if(lines[row] == n) return 1;
            }
            else lines[row] = FAIL;
            if(lines[col + n] >= 0 && lines[col + n] != FAIL) {
                lines[col + n]++;
                if(lines[col + n] == n) return 1;
            }
            else lines[col + n] = FAIL;
            if(row == col){
                if(lines[2*n] >= 0 && lines[2*n] != FAIL) {
                    lines[2*n]++;
                    if (lines[2*n] == n) return 1;
                }
                else lines[2*n] = FAIL;
            }
            if(row + col == n - 1){
                if(lines[2*n + 1] >= 0 && lines[2*n + 1] != FAIL) {
                    lines[2*n + 1]++;
                    if(lines[2*n + 1] == n) return 1;
                }
                else lines[2*n + 1] = FAIL;
            }
        }
        else{
            if(lines[row] <= 0) {
                lines[row]--;
                if(lines[row] == -n) return 2;
            }
            else lines[row] = FAIL;
            if(lines[col + n] <= 0) {
                lines[col + n]--;
                if(lines[col + n] == -n) return 2;
            }
            else lines[col + n] = FAIL;
            if(row == col){
                if(lines[2*n] <= 0) {
                    lines[2*n]--;
                    if (lines[2*n] == -n) return 2;
                }
                else lines[2*n] = FAIL;
            }
            if(row + col == n - 1){
                if(lines[2*n + 1] <= 0) {
                    lines[2*n + 1]--;
                    if(lines[2*n + 1] == -n) return 2;
                }
                else lines[2*n + 1] = FAIL;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 *///
// Created by maoym on 2019/10/5.
//

