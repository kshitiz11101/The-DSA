class Solution
{
    public:
    int f(int i,vector<int>&dp){
        if(i==0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=f(i/2,dp)+f(i/3,dp)+f(i/4,dp);
        return dp[i]=max(sum,i);
    }
        int maxSum(int n)
        {
            //code here.
            vector<int>dp(n+1,-1);
            return f(n,dp);
        }
};
