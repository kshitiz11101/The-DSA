class Solution{
public:
/*
int f(int ind,int W,int val[],int wt[],vector<vector<int>>&dp){
    if(ind==0){
       
         return (W/wt[0])*val[0];
    
    }
    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }
    
    int take=INT_MIN,nottake=f(ind-1,W,val,wt,dp);
    if(wt[ind]<=W){
        take=val[ind]+f(ind,W-wt[ind],val,wt,dp);
    }
    return dp[ind][W]=max(take,nottake);
}
*/
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        /*
        vector<vector<int>>dp(N,vector<int>(W+1,0));
       for (int i = wt[0]; i <= W; i++) {
        dp[0][i] = (i/wt[0])*val[0];
    }
        for(int ind=1;ind<N;ind++){
            for(int w=0;w<=W;w++){
                 int take=INT_MIN,nottake=0+dp[ind-1][w];
            if(wt[ind]<=w){
                take=val[ind]+dp[ind][w-wt[ind]];
            }
            dp[ind][w]=max(take,nottake);
            }
        }
        return dp[N-1][W];
        */
        vector<int>curr(W+1,0);
        for(int i=0;i<=W;i++){
            curr[i]=(i/wt[0])*val[0];
            
        }
         for(int ind=1;ind<N;ind++){
            for(int w=0;w<=W;w++){
                 int take=INT_MIN,nottake=0+curr[w];
            if(wt[ind]<=w){
                take=val[ind]+curr[w-wt[ind]];
            }
            curr[w]=max(take,nottake);
            }
        }
        return curr[W];
        
        // return f(N-1,W,val,wt,dp);
    }
};
