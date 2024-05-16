
class Solution {
public:
int dfs(int parent ,int node,vector<int>adj[],int &ans){
    int count=0;
    for(auto i:adj[node]){
        if(i!=parent){
            count+=dfs(node,i,adj,ans);
        }
    }
    count++;
    if(count%2==0 && node!=1){
        ans++;
        count=0;
    }
    return count;
}
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>adj[n+1];
	    for(auto i:edges){
	        adj[i[0]].push_back(i[1]);
	        adj[i[1]].push_back(i[0]);
	    }
	    int ans=0;
	    dfs(-1,1,adj,ans);
	    return ans;
	}
};
