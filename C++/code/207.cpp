class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> inDegree(numCourses, 0);
        queue<int> sources;
        int visited = 0;
        for (auto& pre: prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                sources.push(i);
            }
        }
        while (!sources.empty()) {
            int source = sources.front();
            sources.pop();
            visited++;
            for (int next: edges[source]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    sources.push(next);
                }
            }
        }
        return visited == numCourses;
    }
};