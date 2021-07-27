class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<int> visited(10000, 0);
        int tar = stoi(target);
        set<int> s;
        for (string end: deadends) {
            s.insert(stoi(end));
        }
        if (s.find(0) != s.end()) return -1;
        queue<int> q;
        q.push(0);
        int ans = -1;
        while (!q.empty()) {
            int sz = q.size();
            ans++;
            for (int i = 0; i < sz; i++) {
                int front = q.front();
                q.pop();
                if (front == tar) return ans;
                if (visited[front]) continue;
                visited[front] = 1;
                if (s.find(front) != s.end()) continue;
                
                for (int j = 0; j < 4; j++) {
                    int num = (int)pow(10, j);
                    if (front / num % 10 == 9) q.push(front - 9 * num);
                    else q.push(front + num);
                    if (front / num % 10 == 0) q.push(front + 9 * num);
                    else q.push(front - num);
                }
            }
        }
        return -1;
    }
};