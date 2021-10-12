class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, map<int, set<pair<int,string>>>> mp; // name time <idx city>
        set<int> idx;
        for (int i = 0; i < transactions.size(); i++) {
            string& trans = transactions[i];
            istringstream ss(trans);
            string buff;
            vector<string> temp;
            while (getline(ss, buff, ',')) {
                temp.push_back(buff);
            }
            
            if (stoi(temp[2]) > 1000) idx.insert(i);
            auto it = mp[temp[0]].lower_bound(stoi(temp[1]) - 60);
            auto it2 = mp[temp[0]].upper_bound(stoi(temp[1]) + 60);
            while (it != it2) {
                for (auto pi: it->second) {
                    if (pi.second != temp[3]) {
                        idx.insert(pi.first);
                        idx.insert(i);
                    }
                }
                it++;
            }
            mp[temp[0]][stoi(temp[1])].insert({i, temp[3]});
        }
        
        vector<string> ans;
        for (int i = 0; i < transactions.size(); i++) {
            if (idx.find(i) != idx.end()) ans.push_back(transactions[i]);
        }
        return ans;
    }
};