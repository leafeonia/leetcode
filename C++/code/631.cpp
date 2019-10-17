#include <bits/stdc++.h>
using namespace std;

class Excel {
public:
    vector<vector<int>> board;
    vector<string> func[27][27];
    int h,w;
    Excel(int H, char W) {
        board = vector<vector<int> >(H + 1,vector<int>(W - 'A' + 1));
        for(auto v:board) v.clear();
        for(int i = 0;i < H;i++) for(int j = 0;j < W - 'A' + 1;j++) func[i][j].clear();
        h = H;
        w = W - 'A' + 1;
    }

    void calc(){
        for (int i = 0; i < h; ++i){
            for(int j = 0;j < w;j++){
                if(!func[i][j].empty()){
                    int val = 0;
                    for(string s: func[i][j]){
                        if(s.length() <= 3){
                            val += board[stoi(s.substr(1)) - 1][s[0] - 'A'];
                        }
                        else{
                            int col1 = s[0] - 'A';
                            int row1 = s[1] - '0';
                            if(s[2] != ':') {
                                row1 = 10*row1 + s[2] - '0';
                                s = s.substr(4);
                            }
                            else s = s.substr(3);
                            int col2 = s[0] - 'A';
                            int row2 = s[1] - '0';
                            if(s.length() > 2) row2 = 10*row2 + s[2] - '0';
                            for(int k = row1 - 1;k <= row2 - 1;k++){
                                for(int l = col1;l <= col2;l++){
                                    val += board[k][l];
                                }
                            }
                        }
                    }
                    board[i][j] = val;
                }
            }
        }
    }

    void set(int r, char c, int v) {
        board[r-1][c - 'A'] = v;
        func[r-1][c - 'A'].clear();
    }

    int get(int r, char c) {
        calc();
        return board[r-1][c - 'A'];
    }

    int sum(int r, char c, vector<string> strs) {
        for(auto s: strs)
            func[r-1][c - 'A'].push_back(s);
        calc();
        return board[r-1][c - 'A'];
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(H, W);
 * obj->set(r,c,v);
 * int param_2 = obj->get(r,c);
 * int param_3 = obj->sum(r,c,strs);
 *///
// Created by maoym on 2019/10/17.
//

