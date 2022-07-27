class Solution {
public:
    // int rec(vector<vector<int>> &grid, vector<vector<bool>> &visited, int res, int x, int y){
//         cout<<res<<"\t"<<x<<"\t"<<y<<endl;
//         if((x > grid.size() && y > grid[x].size() )){
//             return res;
//         }
//         int ans = res;
//         for(int i = x; i < grid.size() ;++i){
//             for(int j = y; j < grid[i].size(); ++j){
//                 // cout<<i<<endl<<j<<endl;
//                 if( visited[i][j] ){
                    
//                     visited[i][j] = true;   
//                     continue;
//                 }
//                 visited[i][j] = true;
//                 if(grid[i][j] == 2){
//                     cout<<"hi\n";
//                     if(i + 1 < grid.size() && grid[i + 1][j] == 1 && !visited[i + 1][j]){
//                         cout<<i + 1<<"\t"<<j<<endl;
//                         grid[i + 1][j] = 2;
//                         ans = max(rec(grid, visited, res + 1, i+1, j), ans);
//                     }
//                     if(i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]){
//                         cout<<i - 1<<"\t"<<j<<endl;
//                         grid[i - 1][j] = 2;
//                         ans = max(ans, rec(grid, visited, res + 1, i-1, j));
//                     }
//                     if(j + 1 < grid[i].size() && grid[i][j + 1] == 1 && !visited[i][j + 1]){
//                         cout<<i<<"\t"<<j + 1<<endl;
//                         grid[i][j + 1] = 2;
//                         ans = max(ans, rec(grid, visited, res + 1, i, j + 1));
//                     }
//                     if(j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]){
//                         cout<<i<<"\t"<<j - 1<<endl;
//                         grid[i][j - 1] = 2;
//                         ans = max(ans, rec(grid, visited, res + 1, i+1, j - 1));
//                     }
                    
//                 }
//             }
//         }  
//         return ans;
        
//     }
    
//     int orangesRotting(vector<vector<int>>& grid) {
//         int res = 0;
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited(n, vector<bool>(m, false));
//         for(int i =0 ; i < grid.size(); ++i){
//             for(int j = 0; j < grid[i].size(); ++j){
//                 if(grid[i][j] == 0){
//                     visited[i][j] = true;
//                 }
//             }
//         }
//         for(int i =0 ; i < grid.size(); ++i){
//             for(int j = 0; j < grid[i].size(); ++j){
//                 if(grid[i][j] == 2 && !visited[i][j]){
//                     // cout<<rec(grid, visited, res, i, j);
//                     res = max(res,rec(grid, visited, 0, i, j));
//                 }
//             }
//         }
//         for(int i =0 ; i < grid.size(); ++i){
//             for(int j = 0; j < grid[i].size(); ++j){
//                 if(grid[i][j] == 1){
//                     cout<<i<<endl<<j<<endl;
//                     return -1;
                    
//                 }
//             }
//         }
//         return res;
//     }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    dfs(grid,i,j,r,c,0,true);
                }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
                ans=max(abs(grid[i][j]),ans);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&grid,int x, int y,int r, int c,int count,bool start){
        if(x<0 || x>=r || y<0 || y>=c || grid[x][y]==0|| grid[x][y]<0 && -grid[x][y]<count )
            return;
        if(grid[x][y]==2 && !start)
            return;
            
        grid[x][y]=-count;
        
        dfs(grid,x+1,y,r,c,count+1,false);
        dfs(grid,x,y+1,r,c,count+1,false);
        dfs(grid,x-1,y,r,c,count+1,false);
        dfs(grid,x,y-1,r,c,count+1,false);
    }
    
    
//     int orangesRotting(vector<vector<int>>& grid) {
//         int dy[] ={0, 0, 1, -1};
//         int dx[] = {1, -1, 0, 0};
//         queue<pair<int, int>> q;
//         int r = grid.size();
//         int c = grid[0].size();
//         int total = 0;
//         for(int i = 0; i < r; ++i){
//             for(int j = 0; j < c; ++j){
//                 if(grid[i][j] != 0){
//                     total++;
//                 }
//                 if(grid[i][j] == 2){
//                     q.push({i,j});
//                 }
//             }
//         }
//         int cnt = 0;
//         int res = 0;
//         while(!q.empty()){
//             int n = q.size();
//             cnt += n;
//             for(int i = 0; i < n ;++i){
//                 auto pr = q.front();
//                 q.pop();
//                 for(int j = 0; j < 4 ;++j){
//                     int x = pr.first + dx[j];
//                     int y = pr.second + dy[j];
//                     if(x >= r || y >= c || x < 0 || y < 0 || grid[x][y] != 1){
//                         continue;
//                     }
//                     grid[x][y] = 2;
//                     q.push({x, y});
//                 }
//             }
//             if(!q.empty()){
//                 res++;
//             }
//         }
//         if(total != cnt){
//             return -1;
//         }
//         return res;
        
//     }   
};