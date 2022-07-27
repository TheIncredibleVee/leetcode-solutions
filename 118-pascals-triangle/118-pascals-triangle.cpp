class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.reserve(numRows);
    ans.push_back({1});
    
    vector<int> prev;
    for(int i=0;i<numRows-1;i++){
        vector<int> temp;
        temp.reserve(i + 1);
        temp.push_back(1);
        
        //logic
        int prevs = prev.size();
        for(int j=0;j<prevs-1;j++)
            temp.push_back(prev[j]+prev[j+1]);
        
        temp.push_back(1);
        
        ans.push_back(temp);
        
        prev = temp;
    }
    
    return ans;
    }
};