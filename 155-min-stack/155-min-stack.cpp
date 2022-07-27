class MinStack {
    private:
        stack<long long > st;
        long long mn;
public:
    MinStack() {
        st = stack<long long>();
        mn = LONG_MAX;
    }
    
    void push(int val) {
        if(mn == LONG_MAX){
            mn = val;
            st.push(1LL*val);
            return;
        }
        if(mn > val){
            st.push(val*2LL - mn);
            mn = val;
            
        }else{
            st.push(val);
        }
    }
    
    void pop() {
         if(st.empty()){
             return;
         }
        if (st.top() <= mn){
            mn = mn * 2LL - st.top();
        }
        st.pop();
        if(st.empty()){
            mn = LONG_MAX;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        if(st.top() <= mn){
            return mn;
        }
        return st.top();
    }
    
    int getMin() {
        if(mn == LONG_MAX){
            return -1;
        }else{
            return mn;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */