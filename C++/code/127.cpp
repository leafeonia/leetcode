class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<string> q;
        q.push(beginWord);
        set<string> s;
        for (string word: wordList) s.insert(word);
        
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string front = q.front();
                q.pop();
                if (front == endWord) return ans;
                for (int j = 0; j < front.length(); j++) {
                    char origin = front[j];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        front[j] = ch;
                        if (s.find(front) != s.end()) {
                            q.push(front);
                            s.erase(front);
                        }
                        
                    }
                    front[j] = origin;
                }
            }
        }
        return 0;
    }
};