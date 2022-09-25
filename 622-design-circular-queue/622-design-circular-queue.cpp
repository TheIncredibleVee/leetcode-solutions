class MyCircularQueue {
private:
    vector<int> queue;
    int start = 0, end = -1, size;
public:
    MyCircularQueue(int k) {
        queue = vector<int>(k, 0);
        start = 0;
        end = -1;
        size = k; 
    }
    bool enQueue(int value) {
        if(end != -1 && ((start == 0 && end == size - 1) || (start == end + 1))){
            return false;
        }else{
            end = (end + 1) % size;
            queue[end] = value;
            return true;
        }
    }
    bool deQueue() {
        if(end != -1){
            if(start == end){
                end = -1;
                start = 0;
                return true;
            }
            start = (start + 1) % size;
            return true;
        }else{
            return false;
        }
    }
    int Front() {
        if(end != -1){
            return queue[start];
        }else {
            return -1;
        }    
    }
    
    int Rear() {
        if(end != -1){
            return queue[end];
        }else {
            return -1;
        }
    }
    bool isEmpty() {
        if(end == -1){
            return true;
        }else{
            return false;
        }
    }
    bool isFull() {
        if(end != -1 && ((start == 0 && end == size - 1) || (start == end + 1))){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */