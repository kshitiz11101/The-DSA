// User function Template for C++
class DisjointSet {
    public:
        vector<int> rank, parent;
        
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            
            for(int i=0; i<=n; i++) {
                parent[i] = i;
            }
        }
        
        int findUParent(int node) {
            if(parent[node] == node)
                return node;
            
            return parent[node] = findUParent(parent[node]);
        }
        
        void unionByRank(int u, int v) {
            int ul_parent_u = findUParent(u);
            int ul_parent_v = findUParent(v);
            
            if(ul_parent_u == ul_parent_v)
                return;
            
            if(rank[ul_parent_u] < rank[ul_parent_v]) {
                parent[ul_parent_u] = ul_parent_v;
            }
            else if(rank[ul_parent_v] < rank[ul_parent_u]) {
                parent[ul_parent_v] = ul_parent_u;
            }
            else {
                parent[ul_parent_v] = ul_parent_u;
                rank[ul_parent_u]++;
            }
        }
};

class Solution {
    private:
    bool isValid(int nrow,int ncol,int n,int m){
        return nrow>=0 && nrow<n && ncol>=0 && ncol<m;
    }
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
        
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col]=1;
            cnt++;
            // row-1,col
            // row,col+1
            // row+1,col
            // row,col-1
            int dr[]={-1,0,+1,0};
            int dc[]={0,1,0,-1};
            
            for(int ind=0;ind<4;ind++){
                int nrow=row+dr[ind];
                int ncol=col+dc[ind];
                if(isValid(nrow,ncol,n,m)){
                    if(vis[nrow][ncol]==1){
                        int nodeNo=row*m+col;
                        int adjNodeNo=nrow*m+ncol;
                        if(ds.findUParent(nodeNo)!=ds.findUParent(adjNodeNo)){
                            cnt--;
                            ds.unionByRank(nodeNo,adjNodeNo);
                        }
                    }
                }
                
            }
            ans.push_back(cnt);
        }
        
        
        
        return ans;
        
    }
};
