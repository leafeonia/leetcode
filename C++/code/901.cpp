struct item{
    int price;
    int num;
    item(int p){price = p;num = 1;}
};

class StockSpanner {
private:
    stack<item> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        item newitem(price);
        while(!s.empty() && s.top().price <= price){
            newitem.num += s.top().num;
            s.pop();
        }
        s.push(newitem);
        return newitem.num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */