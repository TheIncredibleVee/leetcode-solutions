class MyQueue {
    private:
        stack<int> s;
        stack<int> s1;
public:
    MyQueue() {
        s = stack<int>();
        s1 = stack<int>();
    }
    
    void push(int x) {
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!s1.empty()){
            s.push(s1.top());
            s1.pop();
        }
        
    }
    
    int pop() {
        if(s.empty()){
            return -1;
        }
        int res =s.top();
        s.pop();
        return res;
        
    }
    
    int peek() {
        if(s.empty()){
            return -1;
        }
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */