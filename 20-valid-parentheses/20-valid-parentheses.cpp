class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        vector<char> open({'(', '[', '{'});
        vector<char> close({')', ']', '}'});
        for(auto x: st){
            if(find(open.begin(), open.end(), x) != open.end()){
                s.push(x);
            }
            else if(find(close.begin(), close.end(), x) != close.end()){
                int idx = find(close.begin(), close.end(), x) - close.begin(); 
                if(s.empty() || s.top() != open[idx]){
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};