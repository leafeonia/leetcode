class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> path;
    int n;
    
    void dfs(int node) {
        if (node == n - 1) {
            ans.push_back(path);
            return;
        }    
        for (int next: graph[node]) {
            path.push_back(next);
            dfs(next);
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        this->graph = graph;    
        n = graph.size();
        path.push_back(0);
        dfs(0);
        return ans;
    }
};