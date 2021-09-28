class Solution {
public:
    int dist(pair<int, int> a) {
        return a.first * a.first + a.second * a.second;
    }
    struct pointComp {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second; 
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, pointComp> pq;
        int n = points.size();
        for (int i = 0;i < k;i++) {
            pq.push({points[i][0], points[i][1]});
        }
        for (int i = k;i < n;i++) {
            if (dist({points[i][0], points[i][1]}) < dist(pq.top())) {
                pq.pop();
                pq.push({points[i][0], points[i][1]});
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            vector<int> v;
            auto point = pq.top();
            v.push_back(point.first);
            v.push_back(point.second);
            ans.push_back(v);
            pq.pop();
        }
        return ans;
    }
};