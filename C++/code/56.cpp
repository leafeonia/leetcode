/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator < (Interval a,Interval b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size() == 0)
            return ret;
        sort(intervals.begin(),intervals.end());
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= cur.end) cur.end = max(intervals[i].end,cur.end);
            else{
                ret.push_back(cur);
                cur = intervals[i];
            }
        }
        ret.push_back(cur);
        return ret;
    }
};