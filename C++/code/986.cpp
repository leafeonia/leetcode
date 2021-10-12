class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int m = firstList.size(), n = secondList.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            vector<int> a = firstList[i];
            vector<int> b = secondList[j];
            if (a[1] < b[1]) {
                if (a[1] >= b[0]) {
                    vector<int> v{max(a[0], b[0]), min(a[1], b[1])};
                    ans.push_back(v);
                }
                i++;
            } else {
                if (b[1] >= a[0]) {
                    vector<int> v{max(a[0], b[0]), min(a[1], b[1])};
                    ans.push_back(v);
                }
                j++;
            }
        }
        return ans;
    }
};