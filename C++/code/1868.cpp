class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int m = encoded1.size(), n = encoded2.size();
        int i = 0, j = 0, left = 0, right = 0;
        vector<vector<int>> ans;
        while (i < m && j < n) {
            auto& pair1 = encoded1[i];
            auto& pair2 = encoded2[j];
            
            int value = pair1[0] * pair2[0];
            int freq = min(pair1[1], pair2[1]);
            
            pair1[1] -= freq;
            pair2[1] -= freq;
            
            if (pair1[1] == 0) i++;
            if (pair2[1] == 0) j++;
            
            if (ans.empty() || ans.back()[0] != value) {
                vector<int> v{value, freq};
                ans.push_back(v);
            } else {
                ans.back()[1] += freq;
            }
        }
        return ans;
    }
};

// [1 1  1][3 3 ]
// [2 2][4  4 4 ]