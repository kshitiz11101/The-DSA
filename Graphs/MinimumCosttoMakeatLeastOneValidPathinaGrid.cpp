class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
      priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> visited(n, vector<int>(m, 1e9));
        visited[0][0]=0;
       int delrow[]={0,0,1,-1};
        int delcol[]={1,-1,0,0};
        while(!pq.empty()){
           int cost=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
           pq.pop();
           if(row==n-1 && col==m-1){
            return cost;
           }

           for(int ind=0;ind<4;ind++){
            int nrow=row+delrow[ind];
            int ncol=col+delcol[ind];
            int ncost=cost+(ind+1!=grid[row][col]);            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ncost<visited[nrow][ncol]){
                visited[nrow][ncol]=ncost;
                pq.push({ncost,{nrow,ncol}});
            
            }
           }
        }

    return 0;
    }
};
