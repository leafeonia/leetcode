class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (box[i][j] == '#') cnt++;
                else if (box[i][j] == '*') {
                    for (int k = 0; k < cnt; k++) {
                        ans[j - k - 1][m - i - 1] = '#';
                    }
                    ans[j][m - i - 1] = '*';
                    cnt = 0;
                }
            }
            for (int k = 0; k < cnt; k++) {
                ans[n - 1 - k][m - i - 1] = '#';
            }
        }
        return ans;
    }
};