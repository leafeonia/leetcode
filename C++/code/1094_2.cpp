class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> buckets(1001, 0);
        for (auto& trip: trips) {
            buckets[trip[1]] += trip[0];
            buckets[trip[2]] -= trip[0];
        }
        int cur = 0;
        for (int bucket: buckets) {
            cur += bucket;
            if (cur > capacity) return false;
        }
        return true;
    }
};