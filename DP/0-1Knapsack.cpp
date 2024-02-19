class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    /*
    int f(int ind,int w,int wt[],int val[],vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=w){
            return val[0];
            }
            else{
            return 0;
            }
        }
        if(dp[ind][w]!=-1){
            return dp[ind][w];
        }
        int notTake=0+f(ind-1 ,w,wt,val,dp);
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+f(ind-1,w-wt[ind],wt,val,dp);
        }
        return dp[ind][w]=max(take,notTake);
    }
    */
    int knapSack(int W, int wt[], int val[], int n) 
    { vector<int>prev(W+1,0);
    for(int w=wt[0];w<=W;w++){
        prev[w]=val[0];
    }
    
          for(int ind=1;ind<n;ind++){
            for(int w=W;w>=0;w--){
                  int notTake=0+prev[w];
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+prev[w-wt[ind]];
        }
       prev[w]=max(take,notTake);
            }

        }
        
        
        
        return prev[W];
        
        
        
        
        
        
        /*
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int i=wt[0];i<W;i++){
            dp[0][i]=val[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                  int notTake=0+dp[ind-1][w];
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+dp[ind-1][w-wt[ind]];
        }
       dp[ind][w]=max(take,notTake);
            }
        }
        return dp[n-1][W];
        */
    //   return f(n-1,W,wt,val,dp);
    }
};
