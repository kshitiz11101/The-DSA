// User function Template for C++

class Solution {
    
  void dfs(int row,int col, vector<vector<int>>&visited,vector<vector<int>>& grid,vector<pair<int,int>>&ans,int row0,int col0){
      visited[row][col]=1;
      ans.push_back({row-row0,col-col0});
       int n=grid.size(),m=grid[0].size();
      int delrow[]={-1,0,+1,0};
      int delcol[]={0,-1,0,+1};
      for(int i=0;i<4;i++){
          int nrow=row+delrow[i];
          int ncol=col+delcol[i];
          if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
              dfs(nrow,ncol,visited,grid,ans,row0,col0);
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>ans;
                    dfs(i,j,visited,grid,ans,i,j);
                    st.insert(ans);
                }
            }
        }
        return st.size();
    }
};
