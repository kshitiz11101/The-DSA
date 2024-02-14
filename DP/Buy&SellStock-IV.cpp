class Solution {
public:
/*
 int f(int ind,int buy,int trans,int n,vector<int>&price,vector<vector<vector<int>>>&dp){
          
            if(ind==n){
                return 0;
            }
            if(dp[ind][buy][trans]!=-1){
                return dp[ind][buy][trans];
            }
            if(trans==0){
                return 0;
            }
            // int profit=0;
            
                if(buy){
               return dp[ind][buy][trans]=max(-price[ind]+f(ind+1,0,trans,n,price,dp),0+f(ind+1,1,trans,n,price,dp));
                }
                else{
                return dp[ind][buy][trans]=max(price[ind]+f(ind+1,1,trans-1,n,price,dp),0+f(ind+1,0,trans,n,price,dp));
                }
            
            // return dp[ind][buy][trans]=profit;
        }
        */
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        vector<vector<int>>after(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int trans=1;trans<=k;trans++){
                if(buy){
               curr[buy][trans]=max(-prices[ind]+after[0][trans],0+after[1][trans]);
                }
                else{
                curr[buy][trans]=max(prices[ind]+after[1][trans-1],0+after[0][trans]);
                }
                }
                after=curr;
            }
        }
        // return f(0,1,k,n,prices,dp);
        // return dp[0][1][k];
        return curr[1][k];
    }
};
