/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        typedef pair<int,int> pi;
        auto comp = [&](pi a, pi b) {return schedule[a.first][a.second].start > schedule[b.first][b.second].start;};
        priority_queue<pi, vector<pi>, decltype(comp)> pq(comp);
        for (int i = 0; i < schedule.size(); i++) {
            pq.push({i, 0});
        }
        Interval temp = schedule[pq.top().first][pq.top().second];
        vector<Interval> ans;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int i = top.first, j = top.second;
            Interval& itv = schedule[i][j];
            if (itv.start > temp.end) {
                Interval add(temp.end, itv.start);
                ans.push_back(add);
                temp = itv;
            } else {
                temp.end = max(temp.end, itv.end);
            }
            if (j < schedule[i].size() - 1) pq.push({i, j + 1});
        }
        return ans;
    }
};