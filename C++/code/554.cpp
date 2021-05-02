class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int length = 0;
        int row = wall.size();
        for (auto& le: wall[0]) length += le;
        map<int, int> positions;
        for(int i = 0;i < row;i++){
            int added_length = 0;
            for(auto& le: wall[i]){
                added_length += le;
                if (positions.find(added_length) == positions.end()) positions[added_length] = 1;
                else positions[added_length]++;
            }
        }
        int rec = 0;
        for (auto& item: positions) {
            if(item.first != length) rec = max(rec, item.second);
        }
        return row - rec;
    }
};