class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int ast: asteroids) {
            if (st.empty() || st.top() < 0 || (st.top() > 0 && ast > 0)) st.push(ast);
            else {
                if (abs(ast) < st.top()) continue;
                else if (abs(ast) == st.top()) st.pop();
                else {
                    while (!st.empty() && st.top() > 0 && st.top() < abs(ast)) st.pop();
                    if (!st.empty() && st.top() == abs(ast)) st.pop();
                    else if (st.empty() || st.top() < 0) st.push(ast);
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 8 -4 10 -2 -12 1 3 1 -2    -12 1 3