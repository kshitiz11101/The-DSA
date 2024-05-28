
class Solution {
  public:
  int f(int ind,int n,int w,vector<int> &cost,vector<vector<int>>&dp){
      if(w==0)
      return 0;
      if(ind>=n || w<0){
          return 1e9;
      }
      if(dp[ind][w]!=-1){
          return dp[ind][w];
      }
      int nottake=0+f(ind+1,n,w,cost,dp);
      int take=1e9;
      if(cost[ind]!=-1 && w>=ind+1){
          take=cost[ind]+f(ind,n,w-(ind+1),cost,dp);
      }
      return dp[ind][w]=min(take,nottake);
      
      
  }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        int ans=f(0,n,w,cost,dp);
        return ans>=1e9?-1:ans;
    }
};
