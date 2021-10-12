class MovingAverage {
public:
    MovingAverage(int size) {
        sz = size;
        sum = n = 0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        n++;
        if (n > sz) {
            int front = q.front();
            q.pop();
            sum -= front;
            n--;
        }
        return (double) sum / n;
    }
    
    queue<int> q;
    int sz;
    int sum;
    int n;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */