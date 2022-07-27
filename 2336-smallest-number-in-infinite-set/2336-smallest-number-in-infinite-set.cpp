class SmallestInfiniteSet {
    private:
        set<int> st;
        int smallest;
public:
    SmallestInfiniteSet() {
        smallest = 1;
        st = set<int>();
    }
    
    int popSmallest() {
        if(st.empty()){
            return smallest++;
        }else{
            int elem = *st.begin();
            st.erase(st.begin());
            return elem;
        }
    }
    
    void addBack(int num) {
        if(num < smallest){
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */