class Solution {
    private:
     bool dfs(int node, vector<int>&vis,vector<vector<int>>& graph, vector<int>&pathVis, vector<int>&check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,graph,pathVis,check)==true){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
        
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>check(V,0);
        vector<int>safe;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,graph,pathVis,check);
                    
                }
            }
        
        for(int i=0;i<V;i++){
            if(check[i]==1){
                safe.push_back(i);
            }
        }
        return safe;
    }
};
