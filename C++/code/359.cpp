class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!q.empty() && q.front().second + 10 <= timestamp) {
            string toclear = q.front().first;
            s.erase(toclear);
            q.pop();
        }
        if (s.find(message) != s.end()) return false;
        q.push({message, timestamp});
        s.insert(message);
        return true;
    }
    
    queue<pair<string, int>> q;
    set<string> s;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */