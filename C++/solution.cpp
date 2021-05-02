#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int length = 0;
        int row = wall.size();
        for (auto& le: wall[0]) length += le;
        vector<set<int>> positions(row);
        for(int i = 0;i < row;i++){
            int added_length = 0;
            for(auto& le: wall[i]){
                added_length += le;
                positions[i].insert(added_length);
            }
        }
        int rec = 0;
        for (int i = 1;i < length;i++){
            int cur = 0;
            for (int j = 0;j < row;j++){
                if (positions[i].find(i) != positions[i].end()) cur++;
            }
            rec = max(rec, cur);
        }
        return row - rec;
    }
};