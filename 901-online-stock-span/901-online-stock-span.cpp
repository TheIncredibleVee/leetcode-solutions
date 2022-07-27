class StockSpanner {
    private:
        stack<int> s;
        vector<int> vec;
public:
    StockSpanner() {
        s = stack<int>();
        vec = vector<int>();
    }
    
    int next(int price) {
        if(s.empty()){
            s.push(0);
            vec.push_back(price);
            return 1;
        }
        while(!s.empty() && vec[s.top()] <= price){
            s.pop();
        }
        int res;
        if(s.empty()){
            res = vec.size() + 1;
        }else{
            res = vec.size() - s.top();
        }
        s.push(vec.size());
        vec.push_back(price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */