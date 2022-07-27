class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string curr = "";
        for(auto x: version1){
            if(x == '.'){
                v1.push_back(stoi(curr));
                curr = "";
            }
            else{
                curr += x;
            }
        }
        v1.push_back(stoi(curr));
        curr ="";
        for(auto x: version2){
            if(x == '.'){
                v2.push_back(stoi(curr));
                curr = "";
            }
            else{
                curr += x;
            }
        }
        v2.push_back(stoi(curr));
        while(v1.size() > v2.size()){
            v2.push_back(0);
        }
        while(v2.size() > v1.size()){
            v1.push_back(0);
        }
        for(int i = 0; i < v1.size(); ++i){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v2[i] > v1[i]){
                return -1;
            }
        }
        return 0;
    }
};