class Solution {
public:
    inline double profit(int numerator, int denominator) {
        return (double)(numerator + 1) / (denominator + 1) - (double)numerator / denominator;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        typedef pair<int,int> pi;
        auto comp = [&](pi a, pi b){
            return profit(a.first, a.second) < profit(b.first, b.second);
        }; 
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        for (auto& v: classes) {
            pq.push({v[0], v[1]});
        }
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();
            pq.push({top.first + 1, top.second + 1});
        }
        int n = classes.size();
        double ans = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans += (double)top.first / top.second / n; 
        }
        return ans;
    }
};

// 5/6 - 4/5 = 1/30
// 4/6 - 3/5 = 2/30