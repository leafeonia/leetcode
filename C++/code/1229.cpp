class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        sort(slots2.begin(), slots2.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        vector<int> ans;
        int m = slots1.size(), n = slots2.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            vector<int> a = slots1[i];
            vector<int> b = slots2[j];
            int start = max(a[0], b[0]);
            int fin = min(a[1], b[1]);
            if (fin - start >= duration) {
                ans.push_back(start);
                ans.push_back(start + duration);
                return ans;
            }
            if (a[1] < b[1]) i++; // move end, not start
            else j++;
        }
        return ans;
    }
};