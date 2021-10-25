class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(n - 1);
        unordered_map<int, unordered_set<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].insert(i);
        }
        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int front = q.front();
                q.pop();
                if (front == 0) return ans;
                visited[front] = 1;
                vector<int> todel;
                for (int next: mp[arr[front]]) {
                    if (!visited[next]) {
                        q.push(next);
                        todel.push_back(next);
                    }
                }
                for (int del: todel) mp[arr[front]].erase(del);
                if (front >= 1 && !visited[front - 1]) q.push(front - 1);
                if (front < n - 1 && !visited[front + 1]) q.push(front + 1);
            }
            ans++;
        }
        return -1;
    }
};