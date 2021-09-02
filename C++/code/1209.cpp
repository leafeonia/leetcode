class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> letter;
        stack<int> num;
        for (char ch: s) {
            if (letter.empty() || ch != letter.top()) {
                letter.push(ch);
                num.push(1);
            } else {
                num.top()++;
                if (num.top() == k) {
                    num.pop();
                    letter.pop();
                }
            }
        }
        string ans;
        while (!letter.empty()) {
            for (int i = 0; i < num.top(); i++) ans += letter.top();
            letter.pop();
            num.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// letter stack [p 

// number stack [1  