class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_set<int> killed;
        unordered_set<int> safe;
        killed.insert(kill);
        vector<int> path;
        unordered_map<int, int> parent;
        for (int i = 0; i < pid.size(); i++) parent[pid[i]] = ppid[i];
        for (int id: pid) {
            path.clear();
            while (id && killed.find(id) == killed.end() && safe.find(id) == safe.end()) {
                path.push_back(id);
                id = parent[id];
            }
            if (killed.find(id) != killed.end()) {
                for (int k: path) killed.insert(k); 
            } else {
                for (int k: path) safe.insert(k);
            }
        }
        vector<int> ans(killed.begin(), killed.end());
        return ans;
    }
};