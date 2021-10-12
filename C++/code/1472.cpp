class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        cur = homepage;
    }
    
    void visit(string url) {
        if (!cur.empty()) backst.push(cur);
        cur = url;
        while (!fwdst.empty()) fwdst.pop();
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (backst.empty()) break;
            fwdst.push(cur);
            cur = backst.top();
            backst.pop();
        }
        return cur;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (fwdst.empty()) break;
            backst.push(cur);
            cur = fwdst.top();
            fwdst.pop();
        }
        return cur;
    }
    
    string cur;
    stack<string> backst;
    stack<string> fwdst;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */