class Solution {
private:
    vector<string> spt(string& text, string space_delimiter = " "){
        vector<string> words{};

        size_t pos = 0;
        while ((pos = text.find(space_delimiter)) != string::npos) {
            words.push_back(text.substr(0, pos));
            text.erase(0, pos + space_delimiter.length());
        }
        words.push_back(text.substr(0, pos));
        return words;
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for(string &path: paths){
            vector<string> words = spt(path);
            string dir = words[0];
            // cout<<dir<<" "<<words.size()<<endl;
            for(int i = 1; i < words.size(); ++i){
                string file_name = "";
                string curr = words[i];
                int j = 0;
                while(curr[j] != '('){
                    file_name += curr[j++];
                }
                j++;
                string file_contents = "";
                while(curr[j] != ')'){
                    file_contents += curr[j++];
                }
                mp[file_contents].push_back(dir + "/" + file_name);
                // cout<<file_name<<" "<<file_contents<<endl;
            }
        }
        for(pair<string, vector<string>> curr: mp){
            // cout<<curr.first<<endl<<curr.second.size()<<endl;
            if(curr.second.size() >= 2){
                res.push_back(curr.second);
            }
        }
        return res;
    }
};