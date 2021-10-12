class Solution {
public:
    void dfs(int node) {
        ans.push_back(node);
        for (int next: children[node]) {
            dfs(next);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        for (int i = 0; i < pid.size(); i++) {
            children[ppid[i]].push_back(pid[i]);
        }
        dfs(kill);
        return ans;
    }
    
    vector<int> ans;
    unordered_map<int, vector<int>> children;
};