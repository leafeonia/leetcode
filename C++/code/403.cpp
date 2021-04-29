class Solution {
public:
    int dest;
    set<int> s;
    vector<vector<int>> record;
    map<int, int> mp;
    bool dfs(int pos, int k){
        if (pos == dest) {
            record[mp[pos]][k] = 1;
            return true;
        }
        if (!record[mp[pos]][k]) return false;
        if (record[mp[pos]][k] == 1) return true;
        bool result = false;
        bool next = false;
        if (k > 1 && s.find(pos + k - 1) != s.end()) {
            if(dfs(pos + k - 1, k - 1)) result = true;;
            next = true;
        }
        if (s.find(pos + k) != s.end()) {
            if(dfs(pos + k, k)) result = true;;
            next = true;
        }
        if (s.find(pos + k + 1) != s.end()) {
            if(dfs(pos + k + 1, k + 1)) result = true;
            next = true;
        }
        if (result) record[mp[pos]][k] = 1;
        if (!next || !result) record[mp[pos]][k] = 0;
        return result;

    }
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        dest = stones[stones.size() - 1];
        for(int i = 0;i < stones.size();i++) {
            s.insert(stones[i]);
            mp[stones[i]] = i;
            record.resize(stones.size());
            for(auto& line: record){
                line.resize(2000, 2);
            }
        }
        return dfs(1, 1);
    }
};