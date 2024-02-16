class Solution {
public:
/*
int f(int ind,int buy,vector<int>&prices,int n, vector<vector<int>>&dp){
      if(ind>=n){
          return 0;
      }
      if(dp[ind][buy]!=-1){
          return dp[ind][buy];
      }
      int profit=0;
      if(buy==0){
          profit=max(-prices[ind]+f(ind+1,1,prices,n,dp),0+f(ind+1,0,prices,n,dp));
      }
     if(buy==1){
          profit=max(prices[ind]+f(ind+2,0,prices,n,dp),0+f(ind+1,1,prices,n,dp));
      }
      return dp[ind][buy]=profit;
  }
  */
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         vector<vector<int>>dp(n+2,vector<int>(3,0));
         dp[n][0]=dp[n][1]=0;
         for(int ind=n-1;ind>=0;ind--){
             for(int buy=0;buy<2;buy++){
                  int profit=0;
      if(buy==0){
          profit=max(-prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
      }
     if(buy==1){
          profit=max(prices[ind]+dp[ind+2][0],0+dp[ind+1][1]);
      }
      dp[ind][buy]=profit;
             }
         }
         return dp[0][0];
    }
};
class Solution {
public:

    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        //  vector<vector<int>>dp(n+2,vector<int>(3,0));
        vector<int>ahead(2,0),curr(2,0),ahead1(2,0);
        ahead[0]=ahead[1]=0;
        //  dp[n][0]=dp[n][1]=0;
         for(int ind=n-1;ind>=0;ind--){
             for(int buy=0;buy<2;buy++){
                  int profit=0;
      if(buy==0){
          profit=max(-prices[ind]+ahead[1],0+ahead[0]);
      }
     if(buy==1){
          profit=max(prices[ind]+ahead1[0],0+ahead[1]);
      }
      curr[buy]=profit;
             }
             ahead1=ahead;
             ahead=curr;
         }
         return curr[0];
    }
};
