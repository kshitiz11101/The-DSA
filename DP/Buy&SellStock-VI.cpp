class Solution {
public:
/*
int f(int ind,int buy,int n,int fee,vector<int>&prices, vector<vector<int>>&dp){
    if(ind==n){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=0;
    if(buy){
        profit=max(-prices[ind]+f(ind+1,0,n,fee,prices,dp),0+f(ind+1,1,n,fee,prices,dp));
    }
    else{
        profit=max((prices[ind]-fee)+f(ind+1,1,n,fee,prices,dp),0+f(ind+1,0,n,fee,prices,dp));
    }
   return dp[ind][buy]=profit;
}
*/

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        // vector<vector<int>>dp(n+2,vector<int>(2,0));
        vector<int>ahead(2,0),curr(2,0);
        // dp[n][0]=dp[n][1]=0;
         ahead[0]=ahead[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
            if(buy){
                profit=max(-prices[ind]+ahead[0],0+ahead[1]);
            }
            else{
                profit=max((prices[ind]-fee)+ahead[1],0+ahead[0]);
            }
         curr[buy]=profit; 
            }
            ahead=curr;
        }
        return curr[1];
    }
};
