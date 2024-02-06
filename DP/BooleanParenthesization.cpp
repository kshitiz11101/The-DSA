class Solution{
public:
 int mod=1003;
 /*
 int f(int i,int j,int isTrue,string s,vector<vector<vector<int>>>&dp){
     if(i>j){
         return 0;
     }
     if(dp[i][j][isTrue]!=-1){
         return true;
     }
     if(i==j){
         if(isTrue){
             return s[i]=='T';
         }
         else{
             return s[i]=='F';
         }
     }
     int ways=0;
     for(int ind=i+1;ind<j;ind++){
         int lt=f(i,ind-1,1,s,dp);
         int lf=f(i,ind-1,0,s,dp);
         int rt=f(ind+1,j,1,s,dp);
         int rf=f(ind+1,j,0,s,dp);
         if(s[ind]=='&'){
             if(isTrue){
                 ways=(ways+(lt*rt)%mod)%mod;
                 
             }
             else{
                 ways=(ways+(rt*lf)%mod+(lt*rf)%mod+(rf*lf)%mod)%mod;
             }
         }
         else if(s[ind]=='|'){
             if(isTrue){
                 ways=(ways+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
             }
             else{
                 ways=(ways+(rf*lf)%mod)%mod;
             }
         }
         else {
             if(isTrue){
                 ways=(ways+(lt*rf)%mod+(lf*rt)%mod)%mod;
             }
             else{
                 ways=(ways+(lf*rf)%mod+(lt*rt)%mod)%mod;
             }
             
         }
     }
     return  dp[i][j][isTrue]=ways;
 }
 
 */
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){   
                if(i==j){
                    dp[i][j][1]=(s[i]=='T');
                    dp[i][j][0]=(s[i]=='F');
                    
                }
                else{
                     int ways=0;
     for(int ind=i+1;ind<j;ind++){
         int lt=dp[i][ind-1][1];
         int lf=dp[i][ind-1][0];
         int rt=dp[ind+1][j][1];
         int rf=dp[ind+1][j][0];
         if(s[ind]=='&'){
                dp[i][j][1]=(dp[i][j][1]+(lt*rt)%mod)%mod;
                 dp[i][j][0]=(dp[i][j][0]+(rt*lf)%mod+(lt*rf)%mod+(rf*lf)%mod)%mod;
         }
         else if(s[ind]=='|'){
                 dp[i][j][1]=(dp[i][j][1]+(lt*rt)%mod+(lt*rf)%mod+(lf*rt)%mod)%mod;
                 dp[i][j][0]=(dp[i][j][0]+(rf*lf)%mod)%mod;
         }
         else {
                 dp[i][j][1]=(dp[i][j][1]+(lt*rf)%mod+(lf*rt)%mod)%mod;
                 dp[i][j][0]=(dp[i][j][0]+(lf*rf)%mod+(lt*rt)%mod)%mod; 
                 
     }
                }
                

        }
            }
        }
        // return f(0,n-1,1,s,dp);
        return dp[0][n-1][1];
    }
};
