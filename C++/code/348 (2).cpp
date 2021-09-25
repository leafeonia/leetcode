class TicTacToe {
public:
    TicTacToe(int n) {
        sz = n;
        v.resize(2 * sz + 2, 0);
    }
    
    int move(int row, int col, int player) {
        if (player == 1) {
            v[row]++;
            v[sz + col]++;
            if (row == col) v[2 * sz]++;
            if (row + col == sz - 1) v[2 * sz + 1]++;
        } else {
            v[row]--;
            v[sz + col]--;
            if (row == col) v[2 * sz]--;
            if (row + col == sz - 1) v[2 * sz + 1]--;
        }
        if (abs(v[row]) == sz || abs(v[col + sz]) == sz || abs(v[2 * sz]) == sz || abs(v[2 * sz + 1]) == sz) {
            return player;
        }
        return 0;
    }
    
    vector<int> v;
    int sz;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */