class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int, vector<int>> edges(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& pre: prerequisites) {
            edges[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        queue<int> q;
        for (int i = 0;i < numCourses;i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for (auto& next: edges[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if (ans.size() != numCourses) {
            vector<int> empty;
            return empty;
        }
        return ans;
    }
};