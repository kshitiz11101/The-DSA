class Solution {
    private:
    void dfs(int node,vector<int>adj[],int &vcount,int &ecount,vector<int>&visited){
        visited[node]=1;
        vcount+=1;
        ecount+=adj[node].size();
        for(auto i:adj[node]){
            if(visited[i]==0){
                dfs(i,adj,vcount,ecount,visited);
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans=0;
        vector<int>visited(n,0);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
               int vcount=0,ecount=0;
           if(!visited[i]){
               dfs(i,adj,vcount,ecount,visited);
               if(vcount*(vcount-1)==ecount){
                   ans++;
               }
               }  
        }
        return ans;
    }
};
