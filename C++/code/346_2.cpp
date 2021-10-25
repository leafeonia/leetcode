class MovingAverage {
public:
    MovingAverage(int size) {
        sz = size;
        sum = cnt = head = 0;
        v.resize(sz);
    }
    
    double next(int val) {
        ++cnt;
        int tail = (head + 1) % sz;
        sum = sum - v[tail] + val;
        v[tail] = val;
        head = tail;
        return (double)sum / min(cnt, sz);
    }
    
    int sz, cnt, sum, head;
    vector<int> v;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */