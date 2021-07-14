class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n = graph.size();
        vector<vector<int>> rgraph(n); //reverse of original graph;
        vector<int> inDegree(n, 0); //inDegree of rgraph
        for (int from = 0;from < n;from++) {
            for (int to: graph[from]) {
                rgraph[to].push_back(from);
                inDegree[from]++;
            }
        }
        queue<int> q;
        for(int i = 0;i < n;i++) {
            if (inDegree[i] == 0) 
                q.push(i);
        }
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (int child: rgraph[front]) {
                inDegree[child]--;
                if (inDegree[child] == 0)
                    q.push(child);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};