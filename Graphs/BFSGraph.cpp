class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int>q;
        vector<int>visited(V,0);
        vector<int>ans;
        q.push(0);
        visited[0]=1;
        ans.push_back(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // ans.push_back(node);
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};
