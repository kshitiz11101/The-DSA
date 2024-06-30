class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (1e9 + 7);
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        
        pq.push({0,0});
        
        
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto i : adj[node]){
                int adjnode = i.first;
                long long adjweight = i.second;
                
                if(dis + adjweight < dist[adjnode]){
                    dist[adjnode] = adjweight + dis;
                    pq.push({dist[adjnode], adjnode});
                    // IMP
                    ways[adjnode] = ways[node]% mod;
                    //
                }
                else if(dis + adjweight == dist[adjnode])
                {
                    // IMP
                    ways[adjnode] = (ways[adjnode] + ways[node])%mod;
                    //
                }
            }
        }
        return (ways[n - 1]) % mod;
    }
};
