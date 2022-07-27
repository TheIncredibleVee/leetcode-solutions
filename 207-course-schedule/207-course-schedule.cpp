class Solution {
    private:
        vector<vector<int>> graph;
public:
    // bool bfs(vector<vector<int>> &graph, vector<bool> &visited, int i){
    //     queue<pair<int,int>> q;
    //     q.push({i,-1});
    //     visited[i] = true;
    //     while(!q.empty()){
    //         auto temp = q.front().first;
    //         int parent = q.front().second;
    //         q.pop();
    //         for(auto &child: graph[temp]){
    //             if(!visited[child]){
    //                 visited[child] = true;
    //                 q.push({child, temp});
    //             }
    //             else if(child != parent ){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }
    // bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &dfsvis, int source){
    //     visited[source] = true;
    //     dfsvis[source] = true;
    //     for(auto &x: graph[source]){
    //         if(!visited[x]){
    //             if(!dfs(graph, visited, dfsvis, x)){
    //                 return false;
    //             }
    //         }else if(dfsvis[x]){
    //             return false;
    //         }
    //     }
    //     dfsvis[source] = false;
    //     return true;
    // }
    bool detectCyclebfs(vector<vector<int>> &adj, int source){
        int n = adj.size();
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; ++i){
            for(auto x: adj[i]){
                indeg[x]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(!indeg[i]){
                q.emplace(i);
            }
        }
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            n--;
            for(auto x: adj[temp]){
                indeg[x]--;
                if(!indeg[x]){
                    q.emplace(x);
                }
            }
        }
        return n != 0 ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> dfsvis(numCourses, false);
        graph = vector<vector<int>> (numCourses);
        for(auto edge: prerequisites){
            graph[edge[1]].emplace_back(edge[0]);
        }
        for(int i = 0; i < numCourses; ++i){
            if(!visited[i]){
                if(detectCyclebfs(graph, i)){
                    return false;
                }
            }
        }
        return true;
    }
};