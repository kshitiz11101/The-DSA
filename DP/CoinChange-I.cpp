class Solution {
public:
/*
int f(int ind,int target,vector<int>&coins, vector<vector<int>>&dp){
    if(target==0){
        return 0;
    }

   if(ind==0){
       if(target%coins[0]==0){
           return target/coins[0];
       }
       else{
           return 1e9;
       }
   }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int mini=INT_MAX;
    int nottake=0+f(ind-1,target,coins,dp),take=INT_MAX;
    if(coins[ind]<=target){
         take=1+f(ind,target-coins[ind],coins,dp);
    }
    return dp[ind][target]=min(take,nottake);
    }


*/
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int>curr(amount+1,0),prev(amount+1,0);
         for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
               prev[i]=i/coins[0];
            }
            else{
                prev[i]=1e9;
            }
        }
        /*
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
               dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }
        */
         for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                 
        int nottake=0+prev[target],take=INT_MAX;
        if(coins[ind]<=target){
            take=1+curr[target-coins[ind]];
        }
         curr[target]=min(take,nottake);
            }
            prev=curr;
        }
        /*
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                 
        int nottake=0+dp[ind-1][target],take=INT_MAX;
        if(coins[ind]<=target){
            take=1+dp[ind][target-coins[ind]];
        }
         dp[ind][target]=min(take,nottake);
            }
        }
        */
      int ans= prev[amount];
      if(ans>=1e9){
          return -1;
      }
      return ans;
    }
};
