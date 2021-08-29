class Solution {
public:
    bool isRobotBounded(string instructions) {
        for (int i = 0; i < 2; i++) instructions += instructions;
        int x = 0, y = 0, dire = 0;
        vector<vector<int>> dires{{-1,0},{0,1},{1,0},{0,-1}};
        for (char ch: instructions) {
            if (ch == 'G') {
                x += dires[dire][0];
                y += dires[dire][1];
            } else if (ch == 'L') {
                dire = (dire + 3) % 4;
            } else {
                dire = (dire + 1) % 4;
            }
        }
        return x == 0 && y == 0;
    }
};