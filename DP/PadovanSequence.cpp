class Solution
{
    const int mod=1e9+7;
    public:
    int padovanSequence(int n)
    {
       //code here
       vector<int>dp(n+1,0);
       dp[0]=1;
       dp[1]=1;
       dp[2]=1;
       for(int i=3;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-3])%mod;
       }
       return dp[n];
    }
    
};
