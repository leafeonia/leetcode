class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int rec = INT_MAX;
        int ans = -1;
        for (int idx = 0; idx < points.size(); idx++) {
            int i = points[idx][0], j = points[idx][1];
            if (i == x || j == y) {
                int dist = abs(x - i) + abs(y - j);
                if (dist < rec) {
                    rec = dist;
                    ans = idx;
                }
            }
        }
        return ans;
    }
};