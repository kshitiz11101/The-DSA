//User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<vector<int>>&adjlist,vector<int>&visited){
      visited[node]=1;
      for(auto i: adjlist[node]){
          if(!visited[i]){
              dfs(i,adjlist,visited);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adjlist(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
       int count=0;
       vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                count++;
                dfs(i,adjlist,visited);
            }
        }
        return count;
    }
};
