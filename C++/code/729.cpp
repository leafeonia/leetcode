class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start);
        if (it != mp.end() && end > it->first) return false;
        if (it != mp.begin() && prev(it)->second > start) return false;
        mp[start] = end;
        return true;
    }
    
    map<int, int> mp;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */