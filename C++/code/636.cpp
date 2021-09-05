class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> ids;
        int prev = 0;
        for (string log: logs) {
            int pos = log.find(':');
            int id = stoi(log.substr(0, pos));
            log = log.substr(pos + 1);
            pos = log.find(':');
            bool isStart = pos == 5 ? true : false;
            log = log.substr(pos + 1);
            int timeStamp = stoi(log);
            
            if (!ids.empty()) {
                int id = ids.top();
                ans[id] += timeStamp + 1 - isStart - prev;
            }
            prev = timeStamp + 1 - isStart;
            
            if (isStart) {
                ids.push(id);
            } else {
                ids.pop();
            }
        }
        return ans;
    }
};

