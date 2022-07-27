class MedianFinder {
    private:
        priority_queue<int, vector<int>, greater<int>> right;
        priority_queue<int> left;
        int total;
public:
    
    MedianFinder() {
        total = 0;
    }
    
    void addNum(int num) {
        if(this->total % 2){
            if(left.top() < num){
                right.push(num);
            }else{
                left.push(num);
                int temp = left.top();
                left.pop();
                right.push(temp);
            }
        }else{
            if(left.empty() || left.top() > num ){
                left.push(num);
            }else{
                right.push(num);
                int temp = right.top();
                right.pop();
                left.push(temp);
            }
        }
        total++;
    }
    
    double findMedian() {
        // auto x = left;
        // while(!x.empty()){
        //     cout<<x.top()<<"\t";
        //     x.pop();
        // }
        // cout<<endl;
        // auto y = right;
        // while(!y.empty()){
        //     cout<<y.top()<<"\t";
        //     y.pop();
        // }
        // cout<<endl;
        // if (this->total == 0){
        //     return 0.0;
        // }
        if(this->total % 2){
            return left.top();
        }else{
            // cout<<left.top()<<endl<<right.top()<<endl;
            return ((double)left.top() + (double)right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */