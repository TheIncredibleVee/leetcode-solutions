class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &arr, int source, int currState){
        if(arr[source] == currState){
            return true;
        }
        if(arr[source] == -1){
            arr[source] = currState;
            for(auto &x: graph[source]){
                if(!dfs(graph, arr, x, currState == 0 ? 1 : 0)){
                    return false;
                }
            }
        }
        if(arr[source] != currState){
            return false;
        }
        return true;
    }
    bool bfs(vector<vector<int>> &graph, vector<int> &arr, int source){
        queue<int> q;
        q.emplace(source);
        arr[source] = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int currState = arr[temp];
            for(auto &x: graph[temp]){
                if(arr[x] == -1){
                    q.emplace(x);
                    arr[x] = currState == 0 ? 1 : 0;
                }
                else if(currState == arr[x]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> arr(graph.size(), -1);
        for(int i = 0; i < graph.size(); ++i){
            if(arr[i] == -1 && !bfs(graph, arr, i)){
                return false;
            }
        }
        return true;
    }
};