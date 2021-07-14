class Solution {
public:
    vector<vector<int>> m_graph;
    vector<int> state; // 0-white  1-gray  2-black
    
    bool dfs(int node) {
        if (state[node] > 0) return state[node] == 2;
        state[node] = 1;
        for (int child: m_graph[node]) {
            if (state[child] == 1 || !dfs(child)) return false;
        }
        state[node] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        m_graph = graph;
        int n = graph.size();
        state.resize(n, 0);
        vector<int> ans;
        for (int i = 0;i < n;i++) {
            if (dfs(i)) ans.push_back(i);
        }
        return ans;
    }
};