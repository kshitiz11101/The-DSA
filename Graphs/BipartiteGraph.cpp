class Solution {
    private:
    bool check(int start,int V, vector<int>adj[],vector<int>&colors){
        
	    queue<int>q;
	    q.push(start);
	    colors[start]=0;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node]){
	            //if adj[node] is yet not color
	            if(colors[it]==-1){
	                colors[it]=!colors[node];
	                q.push(it);
	            }
	            
	            // is the adjacent node have the same color
	            
	            else if(colors[it]==colors[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>colors(V);
	     for(int i=0;i<V;i++){
	        colors[i]=-1;
	        
	    }
	    for(int i=0;i<V;i++){
	        if(colors[i]==-1){
	            if(check(i,V,adj,colors)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};
