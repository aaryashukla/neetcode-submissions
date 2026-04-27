class Solution {
public:
    void bfs(int row, int col,vector<vector<char>>& grid,vector<vector<int>>&vis ){
      int n = grid.size();
      int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col] = 1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
        for(int i =0;i<4;i++){
            int nr = r+ delrow[i];
            int nc = c+ delcol[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1'&&!vis[nr][nc] ){
            vis[nr][nc] =1;
            q.push({nr,nc});
        }
        }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>>vis(n, vector<int>(m,0));
      int cnt = 0;
      for(int i =0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j]&& grid[i][j] =='1'){
                bfs(i,j,grid,vis);
                cnt++;
            }
        }
        
      }
        return cnt;
        
    }
};
