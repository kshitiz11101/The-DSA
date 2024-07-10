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
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        unordered_map<string,int>m;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
            if(m.find(mail)==m.end()){
                m[mail]=i;
            }
            else{
                ds.unionByRank(i,m[mail]);
            }
            }
        }
        vector<string> mergeMail[n];
        for(auto it:m){
            string mail=it.first;
            int node=ds.findUParent(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0){
                continue;
            }
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
