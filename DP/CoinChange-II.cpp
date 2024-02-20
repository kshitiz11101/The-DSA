class Solution {
public:
/*
int f(int ind,int T,vector<int>&coins,vector<vector<int>>&dp){
      if(ind==0){
          return (T%coins[0]==0);
      }
      if(dp[ind][T]!=-1){
          return dp[ind][T];
      }
      int nontake=f(ind-1,T,coins,dp);
      int take=0;
      if(coins[ind]<=T){
          take=f(ind,T-coins[ind],coins,dp);
      }
      return dp[ind][T]=nontake+take;
  }
  */
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int t=0;t<=amount;t++){
           prev[t]=(t%coins[0]==0);
            
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=amount;T++){
                  int nontake=prev[T];
      int take=0;
      if(coins[ind]<=T){
          take=curr[T-coins[ind]];
      }
      curr[T]=nontake+take;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
