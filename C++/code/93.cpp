class Solution {
public:
    vector<string> ans;
    string ip;
    vector<int> path;
    
    void dfs(int depth, int idx) {
        if (idx >= ip.length()) return;
        if (depth == 3) {
            if (ip[idx] == '0' && idx < ip.length() - 1) return;
            int num = stoi(ip.substr(idx));
            if (num > 255) return;
            string s;
            for (int p: path) {
                s += to_string(p);
                s += ".";
            }
            s += to_string(num);
            ans.push_back(s);
            return;
        }    
        for (int le = 1; le <= 3; le++) {
            if (idx + le >= ip.length()) break;
            if (ip[idx] == '0' && le > 1) continue;
            int num = stoi(ip.substr(idx, le));
            if (num > 255) continue;
            path.push_back(num);
            dfs(depth + 1, idx + le);
            path.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();    
        if (n < 4 || n > 12) return ans;
        ip = s;
        dfs(0, 0);
        return ans;
    }
};