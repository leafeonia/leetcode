class Solution {
public:
    Solution(vector<int>& w) {
        sum = 0;
        for (int i = 0; i < w.size(); i++) {
            sum += w[i];
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
        auto iter = upper_bound(v.begin(), v.end(), rand() % sum);
        return iter - v.begin();
    }
    
    int sum;
    vector<int> v;
    
    //1 3 4
    //1 4 8
    //[0,1) [1,4) [4,8)
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */