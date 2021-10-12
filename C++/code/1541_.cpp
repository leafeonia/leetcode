class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int n = s.length();
        int right = 0; // # of ')' needed
        for (char ch: s) {
            if (ch == '(') {
                if (right % 2 == 1) {
                    right--;
                    ans++;
                }
                right += 2;
            } else {
                right--;
                if (right < 0) {
                    ans++;
                    right += 2; 
                }
            }
        }
        return ans + right;
    }
};