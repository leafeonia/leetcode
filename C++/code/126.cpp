class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<vector<string>> ans;
        vector<string> visited;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                vector<string> front = q.front();
                q.pop();
                string back = front.back();
                for (int j = 0; j < back.length(); j++) {
                    string temp = back;
                    for (char k = 'a'; k <= 'z'; k++) {
                        temp[j] = k;
                        if (dict.find(temp) != dict.end()) {
                            visited.push_back(temp);
                            vector<string> path = front;
                            path.push_back(temp);
                            if (temp == endWord) {
                                ans.push_back(path);
                            } else {
                                q.push(path);
                            }
                        }
                    }
                }
            }
            for (string& str: visited) {
                dict.erase(str);
            }
            visited.clear();
        }
        return ans;
    }
};