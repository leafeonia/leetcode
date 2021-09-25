class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;
        ans.push_back(1);
        while (ans.size() < n) {
            vector<int> temp;
            for (int num: ans) {
                if (num * 2 - 1 <= n) temp.push_back(num * 2 - 1);
            }
            for (int num: ans) {
                if (num * 2 <= n) temp.push_back(num * 2);
            }
            ans = temp;
        }
        return ans;
    }
};