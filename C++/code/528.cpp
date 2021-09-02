class Solution {
public:
    Solution(vector<int>& w) {
        srand(time(0));
        m_w = w;
        sum = 0;
        for (int i = 0; i < m_w.size(); i++) {
            sum += m_w[i];
            m_w[i] = sum;
            mp[sum] = i;
        }
    }
    
    int pickIndex() {
        
        int random = rand() % sum;
        auto it = upper_bound(m_w.begin(), m_w.end(), random);
        if (it == m_w.end()) return m_w.size() - 1;
        else return mp[*it];
    }
    
    vector<int> m_w;
    int sum;
    unordered_map<int, int> mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */