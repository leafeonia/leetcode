class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) v.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        int a = 0, b = 0;
        while (a < v.size() && b < vec.v.size()) {
            if (v[a].first == vec.v[b].first) {
                ans += v[a++].second * vec.v[b++].second;
            } else if (v[a].first < vec.v[b].first) {
                a++;
            } else b++;
        }
        return ans;
    }
    
    vector<pair<int, int>> v;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);