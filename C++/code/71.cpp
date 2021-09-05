
class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp;
        vector<string> v;
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            else if (temp == "..") {
                if (!v.empty()) v.pop_back();
            } else {
                v.push_back(temp);
            }
        }
        if (v.empty()) return "/";
        string ans;
        for (string s: v) ans += "/" + s;
        return ans;
    }
};
