class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for (string cpdomain: cpdomains) {
            int blank = cpdomain.find(' ');
            int num = stoi(cpdomain.substr(0, blank));
            string domain = cpdomain.substr(blank + 1);
            while(1) {
                mp[domain] += num;
                int idx = domain.find('.');
                if (idx == string::npos) break;
                domain = domain.substr(idx + 1);
            } 
        }
        vector<string> ans;
        for (auto& it: mp) {
            ans.push_back(to_string(it.second) + " " + it.first);
        }
        return ans;
    }
};