class LRUCache {
    private:
        unordered_map<int, pair<list<int>::iterator, int>> mp;
        list<int> l;
        int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            auto x = mp[key].first;
            int val = mp[key].second;
            mp.erase(key);
            l.erase(x);
            l.push_front(key);
            mp[key] = {l.begin(), val};
            return val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            l.erase(mp[key].first);
            mp.erase(key);
        }
        else if(l.size() >= cap){
            auto x = l.back();
            l.pop_back();
            mp.erase(x);
        }
        l.push_front(key);
        mp[key] = {l.begin(), value};

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */