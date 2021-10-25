class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        for (string fd: folder) {
            if (ans.empty() || fd.substr(0, ans.back().length() + 1) != ans.back() + "/") ans.push_back(fd);
        }
        return ans;
    }
};