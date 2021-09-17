class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> v(60, 0);
        int ans = 0;
        for (int i = 0; i < time.size(); i++) {
            int num = time[i] % 60 == 0 ? 0 : 60 - time[i] % 60;
            ans += v[num];
            v[time[i] % 60]++;
        }
        return ans;
    }
};