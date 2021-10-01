class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xcnt = 0, ocnt = 0, xwin = 0, owin = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'O') ocnt++;
                else if (board[i][j] == 'X') xcnt++;
            }
        }
        if (ocnt > xcnt || xcnt - ocnt > 1) return false;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') xwin++;
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') xwin++;
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') owin++;
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') owin++;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'O') owin++;
            else if (board[0][0] == 'X') xwin++;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'O') owin++;
            else if (board[0][2] == 'X') xwin++;
        }
        if (owin & xwin) return false;
        if (xwin && xcnt != ocnt + 1) return false;
        if (owin && ocnt != xcnt) return false;
        return true;
    }
};