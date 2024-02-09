 int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int ans=0;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[i-1]){
                    int val=1+dp[i-1][j-1];
                    dp[i][j]=val;
                    ans=max(ans,val);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
