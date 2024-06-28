// User function Template for C++

class Solution {
  public:
  const int mod=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int>dist(100000,1e9);
        dist[start]=0;
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second;
            q.pop();
            
            for(auto iter:arr){
                int num=(iter*node)%mod;
                if(steps+1<dist[num]){
                    dist[num]=steps+1;
                    if(num==end){
                        return steps+1;
                    }
                    q.push({steps+1,num});
                }
            }
            
        }
        if(start==end){
            return 0;
        }
        return -1;
    }
};
