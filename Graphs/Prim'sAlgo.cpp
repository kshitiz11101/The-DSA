class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>visited(V,0);
        int sum=0;
        
        // {Wt,Node}
        q.push({0,0});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int wt=it.first;
            int node=it.second;
            if(visited[node]==1){
                continue;
            }
            
            visited[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edW=it[1];
                if(!visited[adjNode]){
                    q.push({edW,adjNode});
                }
            }
            
        }
        return sum;
    }
};
