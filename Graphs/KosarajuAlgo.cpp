class Solution
{
	private:
	
	void dfs(int node, vector<int>&visited,vector<vector<int>>& adj,stack<int>&st){
	    visited[node]=1;
	    for(auto it:adj[node]){
	        if(!visited[it]){
	            dfs(it,visited,adj,st);
	        }
	    }
	    st.push(node);
	}
	//Function to find number of strongly connected components in the graph.
	
	
	void dfs3(int node,vector<int>&visited,vector<int> adjT[]){
	      visited[node]=1;
	    for(auto it:adjT[node]){
	        if(!visited[it]){
	            dfs3(it,visited,adjT);
	        }
	    }
	    
	}
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        // Step-1 Sort all edges on the basis of finishing time
        vector<int>visited(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,st);
            }
        }
        
        // Step-2 Reverse the Graph
        vector<int>adjT[V];
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto it:adj[i]){
                // i->it;
                adjT[it].push_back(i);
            }
        }
        // Step-3 Do DFS
        int scc=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            
            if(!visited[node]){
                scc++;
                dfs3(node,visited,adjT);
            }
        }
        
        return scc;
    }
};
