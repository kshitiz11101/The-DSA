class Solution
{
    public:
const int mod =1e9+7;
    int solve(int i, int j, int n, int m, string s, string t, vector<vector<int>> &dp) 
    {
        if(j == m)
            return 1;
            
        if(i == n)
            return 0;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == t[j]) 
        {
            int notTake = solve(i + 1, j, n, m, s, t, dp);
            int take = solve(i + 1, j + 1, n, m, s, t, dp);
            dp[i][j] = (notTake + take) % mod;
        } else 
        {
            dp[i][j] = solve(i + 1, j, n, m, s, t, dp) % mod;
        }
        
        return dp[i][j] % mod;
    }  
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n=s.size(),m=t.size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return solve(0,0,n,m,s,t,dp)%mod;
    }
};
