class Solution {

  public:
  
    int lcs(string x,string y,int n,int m){
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
     for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
    }
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        int n=x.size(),m=y.size();
        return ((n-lcs(x,y,n,m))*costX)+((m-lcs(x,y,n,m))*costY);
        
    }
};
