class MyCalendar {
private:
    map<int, int> mp;
public:
    MyCalendar() {
        mp = map<int,int>();
    }
    
    bool book(int start, int end) {
        auto ub = mp.upper_bound(start);
        auto lb = ub;
        if(ub == mp.begin()){
            lb = mp.end();
        }else{
            lb--;
        }
        // for(auto x: mp){
        //     cout<<x.first<<"\t"<<x.second<<endl;
        // }
        if(ub != mp.end()){
            cout<<"UB"<<ub->first<<"\t"<<ub->second<<endl;
        }
        if((lb != mp.end() && start < lb->second) || (ub != mp.end() && end > ub->first)){
            return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */