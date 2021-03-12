#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> visited;
    string word;
    int x_max;
    int y_max;
    bool dfs(int x, int y, int index, vector<vector<char>>& board){
        if (x < 0 || x >= x_max || y < 0 || y >= y_max) return false;
        if (visited[x][y]) return false;
        if (index == word.length()) return true;
        if (board[x][y] != word[index]) return false;
        visited[x][y] = 1;
        bool valid = dfs(x+1, y, index+1, board) || dfs(x-1, y, index+1, board) || dfs(x, y+1, index+1, board) || dfs(x, y-1, index+1, board);
        visited[x][y] = 0;
        return valid;

    }

    bool exist(vector<vector<char>>& board, string word2) {
        if (board.empty()) return false;
        word = word2;
        x_max = board.size();
        y_max = board[0].size();
        visited = vector<vector<int>>(x_max, vector<int>(y_max, 0));
        for(int i = 0;i < x_max;i++){
            for(int j = 0;j < y_max;j++){
                if (dfs(i, j, 0, board)) return true;
            }
        }
        return false;
    }



};

//#include <bits/stdc++.h>
//using namespace std;
//
//
//class Solution {
//public:
//    vector<vector<int>> mGrid;
//    int m, n;
//    vector<vector<int>> visited;
//    bool success = false;
//    const int LEFT = 0, UP = 1, RIGHT = 2, DOWN = 3;
//    int towardList[7][4] = {{0, 0, 0, 0}, {LEFT, -1, RIGHT, -1}, {-1, UP, -1, DOWN}, {-1, LEFT, DOWN, -1}, {DOWN, RIGHT, -1, -1},
//                            {-1, -1, UP, LEFT}, {UP, -1, -1, RIGHT}};
//    int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
//    void dfs(int x, int y, int towards){
//        if (success) return;
//        if (x < 0 || x >= m || y < 0 || y >= n) return;
//        if (visited[x][y]) return;
//        int to = towardList[mGrid[x][y]][towards];
//        if (to == -1) return;
//        if (x == m - 1 && y == n - 1) {
//            success = true;
//            return;
//        }
//        visited[x][y] = true;
//        dfs(x + direction[to][0], y + direction[to][1], to);
//        visited[x][y] = false;
//    }
//    bool hasValidPath(vector<vector<int>>& grid) {
//        if (grid.empty()) return false;
//        if (grid[0].empty()) return false;
//        mGrid = grid;
//        m = grid.size();
//        n = grid[0].size();
//        visited = vector<vector<int>>(m, vector<int>(n, 0));
//        dfs(0, 0, DOWN);
//        dfs(0, 0, UP);
//        dfs(0, 0, LEFT);
//        dfs(0, 0, RIGHT);
//        return success;
//    }
//};